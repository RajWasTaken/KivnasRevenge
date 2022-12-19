/**
* @author Kaelan Croucher <kaelan.croucher@uleth.ca>
 * @date December 9th, 2022
 */
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <typeinfo>
#include "GameMain.h"
#include "Item.h"
#include "MainScreenBuilder.h"
#include "ConcreteState.h"
#include "RoomFactory.h"
#include "Rooms.h"
#include "NPC.h"
#include "ComputerNPC.h"

GameMain::GameMain() {
  std::string s0 = "./docs/Setup/SetupBasic.txt";
  std::string s1 = "./docs/AnvikDialogue.txt";
  Stages = new StatePrologue;

  // Instantiation of room variables to be filled in by text file
  StateRoomCreater(s0);

  // add npcs.
  NPCRoomCreater(0, 1, s1, 0);

  //NPCRoomCreater(2, 1, s3, zero); for marcus I need the room location
  GameQuit = false;
  Mike_Mahon.SetLocation(2, 3);
  Objective = "Go talk to Dr.Anvik in his lab. ";
}
// Default Destructor
GameMain::~GameMain() {
}

void GameMain::DeleteBuildings() {
  for (int i = 0; i < LEVEL; i++) {
    for (int z = 0; z < PLACE; z++) {
      delete Building[i][z];
    }
  }
}

bool GameMain::StartMenu() {
  bool GameReset;

  int Input = inputchecker.PrintStartMenu();
  switch (Input) {
    case 1:
      GameReset = true;
      GameQuit = false;
      break;
    case 2:
      inputchecker.PrintInstructScreen();
      StartMenu();
      break;
    case 3:
      GameReset = false;
      GameQuit = true;
      break;
  }
  return GameReset;
}

bool GameMain::PrintMoveMenu() {
  /*C++ matrix coordinates are backwards and upside down.
   * so the access is [y][x]
   * [y-1][x] is going up in the matrix
   * [y+1][x] is going down in the matrix
   * left and right is as expected
   *   *aside from x being the second access of the array
   * [0][0] the origin point is the top left corner of the array.
   * If you have any questions ask Kaelan or google a picture :) */

  std::string MoveOptions = current_room->GetMoveSet();
  inputchecker.ClearScreen();

  inputchecker.PrintMenuPrompt("Where would you like to move? ");

  for (int i = 0; i < MoveOptions.length(); i++) {
    int MoveOpt = MoveOptions[i] - 48;
    switch (MoveOpt) {
      case 1: {
        std::string MenuOpt = std::to_string(i + 1) + ". Left: "
            + Building[Mike_Mahon.GetLocationLevel()][Mike_Mahon
                .GetLocationPlace() - 1]->GetRoomName();
        inputchecker.PrintMenuPrompt(MenuOpt);
        break;
      }
      case 2: {
        std::string MenuOpt = std::to_string(i + 1) + ". Right: "
            + Building[Mike_Mahon.GetLocationLevel()][Mike_Mahon
                .GetLocationPlace() + 1]->GetRoomName();
        inputchecker.PrintMenuPrompt(MenuOpt);
        break;
      }
      case 3: {
        std::string MenuOpt = std::to_string(i + 1) + ". Upstairs: "
            + Building[Mike_Mahon.GetLocationLevel() - 1][Mike_Mahon
                .GetLocationPlace()]->GetRoomName();
        inputchecker.PrintMenuPrompt(MenuOpt);
        break;
      }
      case 4: {
        std::string MenuOpt = std::to_string(i + 1) + ". Downstairs: "
            + Building[Mike_Mahon.GetLocationLevel() + 1][Mike_Mahon
                .GetLocationPlace()]->GetRoomName();
        inputchecker.PrintMenuPrompt(MenuOpt);
        break;
      }
      case 5: {
        std::string MenuOpt = std::to_string(i + 1) + ". Dumbwaiter: "
            + Building[LEVEL - Mike_Mahon.GetLocationLevel() - 1][Mike_Mahon
                .GetLocationPlace()]->GetRoomName();
        inputchecker.PrintMenuPrompt(MenuOpt);
        break;
      }
    }
  }
  inputchecker.PrintMenuPrompt(
      std::to_string(MoveOptions.length() + 1) + ". Back ");

  int MoveChoice = inputchecker.CheckInput(MoveOptions.length() + 1);

  if (MoveChoice == MoveOptions.length() + 1) {
    return false;
  } else {
    MovePlayer(MoveChoice);
    return true;
  }
}

bool GameMain::PrintInventoryMenu() {
  std::string MenuOpt;

  inputchecker.ClearScreen();

  if (!Mike_Mahon.HasItems()) {
    std::string MenuPrompt = "There are no items in your inventory.";
    inputchecker.PrintMenuPrompt(MenuPrompt);
  } else {
    std::string InvMessage = "You have these items in your inventory.";
    inputchecker.PrintMenuPrompt(InvMessage);
    Mike_Mahon.PrintInv();
  }

  MenuOpt = "Press any key 1 - 9 to continue. ";
  inputchecker.PrintMenuPrompt(MenuOpt);

  inputchecker.CheckInput(9);
  return false;
}

bool GameMain::PrintPickupMenu() {
  inputchecker.ClearScreen();
  bool RoomHasItems = current_room->PrintInventory();

  if (RoomHasItems) {
    inputchecker.PrintMenuPrompt("Would you like to pick up an Item?");
    inputchecker.PrintMenuPrompt("1: Yes     2: No");
    int MenuAction = inputchecker.CheckInput(2);

    switch (MenuAction) {
      case 1: {
        inputchecker.ClearScreen();
        current_room->PrintInventory();
        inputchecker.PrintMenuPrompt("Which Item would you like to Pick Up? ");

        int ItemSelection = inputchecker.CheckInput(current_room->GetInvSize());

        bool ItemPickedUp = current_room->TransferItem(ItemSelection);

        if (ItemPickedUp) {
          Mike_Mahon.CallAdd(current_room->SelectedItem);
          inputchecker.PrintMenuPrompt("Item successfully picked up. ");
          return true;
        } else {
          inputchecker.PrintMenuPrompt("Sorry you can't pick that up. ");
          return false;
        }
        static Events *instance;

        break;
      }
      case 2:
        return false;
        break;
    }
  } else {
    inputchecker.PrintMenuPrompt("There are no items in this room. ");
    inputchecker.PrintMenuPrompt("Press any key 1 - 9 to continue. ");
    int input = inputchecker.CheckInput(9);
    if (input != 0) {
      return false;
    }
  }
  return false;
}

bool GameMain::MainMenu() {
  bool TurnUsed = false;
  current_room = Building[Mike_Mahon.GetLocationLevel()][Mike_Mahon
      .GetLocationPlace()];
  //The Idea here is we will update the objective based on the current state
  //we will have to write a function that gets a state
  //and determine the objective string.
  while (!TurnUsed) {
    inputchecker.GameScreenBuilder(Mike_Mahon.GetLocationLevel(),
                                   current_room->GetRoomName(),
                                   current_room->GetRoomDescription(),
                                   Objective, Sound);
    int RoomType = current_room->GetRoomType();
    bool isSearched = current_room->ItemsHidden();
    std::string NPCName;
    if (RoomType == 3) {
      NPCName = current_room->NPCName();
    } else {
      NPCName = "";
    }
    int CurrentStage = Stages->CurrentState();
    int RoomAction = inputchecker.PrintMainMenu(RoomType, isSearched, NPCName,
                                                CurrentStage);

    switch (RoomAction) {
      case 1:
        current_room->SearchIntensely();
        inputchecker.GameScreenBuilder(Mike_Mahon.GetLocationLevel(),
                                       current_room->GetRoomName(),
                                       current_room->GetRoomDescription(),
                                       Objective, Sound);
        inputchecker.ClearScreen();
        PrintPickupMenu();
        TurnUsed = true;
        break;

      case 2:
        TurnUsed = PrintMoveMenu();
        break;

      case 3:
        TurnUsed = PrintInventoryMenu();
        break;

      case 4:
        if (inputchecker.PrintPauseMenu() == 2) {
          GameQuit = true;
          TurnUsed = true;
          break;
        } else {
          break;
        }

      case 5:
        current_room->RoomAction();
        TurnUsed = true;
        break;

      case 6:
        TurnUsed = PrintPickupMenu();
        break;
    }
  }
  return TurnUsed;
}

void GameMain::MovePlayer(int Movement) {
  std::string MoveSet = current_room->GetMoveSet();
  /*C++ matrix coordinates are backwards and upside down.
   * so the access is [y][x]
   * [y-1][x] is going up in the matrix
   * [y+1][x] is going down in the matrix
   * left and right is as expected
   *   *aside from x being the second access of the array
   * [0][0] the origin point is the top left corner of the array.
   * If you have any questions ask Kaelan or google a picture :) */
  Mike_Mahon.MoveHero(MoveSet[Movement - 1] - '0');
}

void GameMain::KivnaUpdater(int state) {
  if (state > 1) {
    int loudness = 0, noiseplace, noiselevel;
    for (int level = 0; level < LEVEL; level++) {
      for (int place = 0; place < PLACE; place++) {
        if (Building[level][place]->GetNoise() != 0) {
          loudness = Building[level][place]->GetNoise();
          noiseplace = place;
          noiselevel = level;
          Building[level][place]->SetNoise(0);
        }
      }
    }
    // Now I need to test how far he is, and
    // see if destination needs to be re-set.
    int difLevel = Kivna->GetLocationLevel() - Mike_Mahon.GetLocationLevel();
    // this is just for the demo.
    int difPlace = Kivna->GetLocationPlace() - Mike_Mahon.GetLocationPlace();

    switch (loudness) {
      case 1:
        // same floor, one room away
        if (Mike_Mahon.GetLocationLevel() == Kivna->GetLocationLevel()
            && difPlace < 2) {
          DestinationPlace = noiseplace;
          DestinationLevel = noiselevel;
        }
        break;
      case 2:
        // kivna is at most one row away
        if (difLevel > -2 && difLevel < 2) {
          DestinationPlace = noiseplace;
          DestinationLevel = noiselevel;
        }
        break;
      case 3:
        DestinationPlace = noiseplace;
        DestinationLevel = noiselevel;
        break;
    }
    Kivna->MoveTeacher(DestinationLevel, DestinationPlace);
    KivnaSound(state);
  }
}

bool GameMain::CheckDeath(int state) {
  bool Perished = false;
  if (state < 2) {
    Perished = false;
  } else {
    if ((Kivna->GetLocationPlace() == Mike_Mahon.GetLocationPlace()
        && Kivna->GetLocationLevel() == Mike_Mahon.GetLocationLevel())) {
      int HasDucks = Mike_Mahon.StateChecker("Ducks");
      switch (HasDucks) {
        case 0:
          inputchecker.PrintDeathScreen();
          GameQuit = true;
          Perished = true;
          break;
        default:
          Mike_Mahon.SetRobbed();
          Perished = false;
      }
    }
  }
  return Perished;
}

// IN PROGRESS
void GameMain::GameLoop(void) {
  bool FirstRound = true;
  Mike_Mahon.SetLocation(1, 0);
  while (!GameQuit) {
    // START OF GAME LOOP
// Evaluate if Kivna has unalived you
    if (FirstRound) {
      inputchecker.PrintPrologueScreen();
      FirstRound = false;
    }
    int CurrentStage = Stages->CurrentState();
    KivnaUpdater(CurrentStage);
    CheckDeath(CurrentStage);
    MainMenu();
    CheckDeath(CurrentStage);
    if (CurrentStage == 12) {
      death_counter++;
    }
    // Second, I have to update the location of Kivna.
    // this means I must find the locaiton with a noise value.

    //Now we have to check if the state changes.
    int a = Stages->EndTest(StateMover(Stages->CurrentState()));
    if (a) {
      delete Stages;
      switch (a) {
        case 1:
          Objective = "Go flip the breaker in the furnace room. ";
          inputchecker.PrintStateScreen(CurrentStage);
          Stages = new StateTalkAnvik();
          break;

        case 2:
          Objective = "Talk to whoever spoke. ";
          inputchecker.PrintStateScreen(CurrentStage);
          Kivna = new Teacher();
          Kivna->SetLocation(0, 1);
          DestinationPlace = 1;
          DestinationLevel = 0;
          Stages = new StateGameStart();
          break;

        case 3:
          DeleteBuildings();
          StateRoomCreater("./docs/Setup/SetupPassword.txt");
          inputchecker.PrintStateScreen(CurrentStage);

          Objective =
              "Nicole won't let you into her lab. Find a way to unlock it... ";
          Stages = new StateFindPassword();
          break;

        case 4:

          DeleteBuildings();
          StateRoomCreater("./docs/Setup/SetupOpenRoom.txt");
          NPCRoomCreater(2, 1, "./docs/NicoleDialogue.txt", 0);
          inputchecker.PrintStateScreen(CurrentStage);
          Objective = "Go talk to Nicole. ";
          Stages = new StateTalkNiko1();
          break;

        case 5:
          DeleteBuildings();
          StateRoomCreater("./docs/Setup/SetupDucks.txt");
          NPCRoomCreater(2, 1, "./docs/NicoleDialogue.txt", 0);
          inputchecker.PrintStateScreen(CurrentStage);
          Objective = "Find all of the ducks around the facility. ";
          Stages = new StateDuckHunting();
          break;

        case 6:
          Objective = "Return to Nicole. ";
          Building[2][1]->SetRoomActionFlag();
          inputchecker.PrintStateScreen(CurrentStage);
          Stages = new DuckTalkToNiko();
          break;

        case 7:
          DeleteBuildings();
          StateRoomCreater("./docs/Setup/SetupAI.txt");
          NPCRoomCreater(2, 1, "./docs/NicoleDialogue.txt", 0);
          Building[2][1]->SetRoomActionFlag();
          Building[0][1]->AddNPC(new ComputerNPC("", 0, 0));
          inputchecker.PrintStateScreen(CurrentStage);
          Objective = "Get to Dr. Anviks lab and debug the Kivna AI. ";
          Stages = new StateCompLab();
          break;

        case 8:
          inputchecker.PrintStateScreen(7);
          Objective =
              "KINVA has taken all your ducks, Go regroup with Nicole... ";
          Building[2][1]->SetRoomActionFlag();
          Building[2][1]->SetRoomActionFlag();
          Stages = new StateTalkNiko2();
          break;

        case 9:
          DeleteBuildings();
          StateRoomCreater("./docs/Setup/SetupBomb.txt");
          NPCRoomCreater(2, 1, "./docs/NicoleDialogue.txt", 0);
          inputchecker.PrintStateScreen(CurrentStage);
          Building[2][1]->SetRoomActionFlag();
          Building[2][1]->SetRoomActionFlag();
          Objective = "Find all of the bomb parts. ";
          Stages = new StateBombHunting();
          break;

        case 10:
          Objective = "Return to Nicole. ";
          inputchecker.PrintStateScreen(CurrentStage);
          Building[2][1]->SetRoomActionFlag();
          Stages = new BombTalkToNiko();
          break;

        case 11:
          inputchecker.PrintStateScreen(CurrentStage);
          Objective = "Set the bomb up in the Furnace Room... ";
          Stages = new StateFurnaceRoom();
          break;

        case 12:
          Objective = "Get out of the building!!! In: "
              + std::to_string(6 - death_counter) + " Moves.";
          Stages = new StateGetOut();
          break;

        default:
          Objective = "Get out of the building!!! In: "
              + std::to_string(6 - death_counter) + " Moves.";
          inputchecker.PrintStateScreen(CurrentStage);
          Stages = new StatePrologue;
          break;
      }
    }
  }
}

int GameMain::StateMover(int StateOfTheTimes) {
  switch (StateOfTheTimes) {
    //Prologue is ending? // done unless we want to move anvik
    //yes - you talked to anvik
    case 0:
      if (Building[0][1]->GetRoomActionFlag()) {
        return 1;
      } else {
        return 0;
      }
      break;
      //TalkToAnvik is ending?
    case 1:
      if (Building[2][3]->GetRoomActionFlag() == 1) {
        return 1;

      } else {
        return 0;
      }
      break;
      //StateGameStart is ending?
      //yes - have you been to to room before nichole's?
      //after this we need to allow searching.
    case 2:
      if ((Mike_Mahon.GetLocationPlace() == 1)
          && (Mike_Mahon.GetLocationLevel() == 2))
        return 1;
      else
        return 0;

      break;
      //StateFindPassword is ending?
      //yes - is the room at [1][3] searched?
      //unlock nichole's room upon exiting this state or starting the next.
    case 3:
      if (Building[1][3]->IsSearched == 1)
        return 1;
      else
        return 0;
      break;

      //TalkToNiko1 is ending?
      //yes - have you talked to nichole?
    case 4:
      if (Building[2][1]->GetRoomActionFlag()) {
        return 1;
      } else {
        return 0;
      }
      break;

      //Searching for ducks is ending?
      //yes - have you collected all ducks and talked to nichole?
      // or
      //yes - have you encountered Dr.Anvik after collecting a duck?
//TO DO: ANOTHER STATE. NEED
    case 5:
      if (Mike_Mahon.GetRobbed()) {
        Mike_Mahon.StateItemDeleter("Ducks");
        Mike_Mahon.SetLocation(2, 1);
        Kivna->SetLocation(0, 1);
        return 2;
      } else if (Mike_Mahon.StateChecker("Ducks") == 4) {
        return 1;
      } else {
        return 0;
      }
      break;

    case 6:
      if (Mike_Mahon.GetRobbed()) {
        Mike_Mahon.StateItemDeleter("Ducks");
        Mike_Mahon.SetLocation(2, 1);
        Kivna->SetLocation(0, 1);
        DestinationPlace = 1;
        DestinationLevel = 0;
        return 2;
      }
      if (Building[2][1]->GetRoomActionFlag()) {
        Mike_Mahon.StateItemDeleter("Ducks");
        return 1;
      } else {
        return 0;
      }
      break;

      // is compLab ending?
      // yes - how? You can't leave this state.
      // Return 4? to leave the house?
    case 7:
      if (Building[0][1]->WinCondtionFlag() == 2) {
        GameQuit = true;
        return 0;
      } else if (Building[0][1]->WinCondtionFlag() == 1) {
        GameQuit = true;
        return 0;
      } else {
        return 0;
      }
      break;

      // is StateTalkToNiko2 ending?
      // yes - have you talked to nichole?
    case 8:
      if (Building[2][1]->GetRoomActionFlag())
        return 1;
      else
        return 0;
      break;

      // is StateBombHunting ending?
      // yes - do you have all bombs and talk to Nichole?
    case 9:
      if (Mike_Mahon.StateChecker("BombParts") == 4) {
        return 1;
      } else {
        return 0;
      }
      break;

    case 10:
      if (Building[2][1]->GetRoomActionFlag()) {
        Mike_Mahon.StateItemDeleter("BombParts");
        return 1;
      } else {
        return 0;
      }
      break;

      // is StateFurnaceRoom ending?
      // yes - you set the bomb.
    case 11:

      if (Building[2][3]->GetRoomActionFlag()) {
        return 1;
      } else {
        return 0;
      }
      break;

    case 12:
      Objective = "Get out of the building!!! In: "
          + std::to_string(6 - death_counter) + " Moves.";
      if (death_counter > 6) {
        std::string head_win = "You were blown up by the bomb.";
        std::string body_win = "Be quicker next time!";
        inputchecker.PrintExtraScreen(head_win, body_win);
        GameQuit = true;
        return 0;
      } else if (death_counter <= 6 && Mike_Mahon.GetLocationPlace() == 0
          && Mike_Mahon.GetLocationLevel() == 1) {
        std::string head_loss = "You successfully escaped the building"
            " before the bomb went off. ";
        std::string body_loss =
            "As you look back through the main door, you see Nicole elevated"
                " in the air as Kivna extracts her soul "
                "and imbues it into a duck he holds"
                " in his hand. Just as the last vestiges "
                "of life escape Nicole's eyes,"
                " they are both consumed in a glaring "
                "light as the bomb detonates.";
        inputchecker.PrintExtraScreen(head_loss, body_loss);
        GameQuit = true;
        return 0;
      }
      break;
  }
  return 0;
}

void GameMain::StateRoomCreater(std::string s) {
  std::string Name, Description, Extreme, Serch, ItemQ, ItemDescription,
      Directions, RoomType;
// Declaration of a factory
  RoomFactory FACTS;
  int ItemAmount;

  std::ifstream RCule;
  RCule.open(s);
  for (int floor = 0; floor < LEVEL; floor++) {
    for (int room = 0; room < PLACE; room++) {
      std::getline(RCule, RoomType);
      std::getline(RCule, Name);
      std::getline(RCule, Description);
      std::getline(RCule, Extreme);
      std::getline(RCule, Serch);
      std::getline(RCule, Directions);
      std::getline(RCule, ItemQ);
      Building[floor][room] = FACTS.GetRoom(RoomType, Name, Description,
                                            Extreme, Serch, false, Directions);
      ItemAmount = ItemQ[0];
      ItemAmount -= 48;

      for (int i = 0; i < ItemAmount; i++) {
        std::getline(RCule, ItemDescription);
        Item *s = new Item(ItemDescription);
        Building[floor][room]->AddItem(s);
      }
      std::getline(RCule, ItemQ);  // get blank line
    }
  }
  RCule.close();
}

void GameMain::NPCRoomCreater(int x, int y, std::string s, int CurrentState) {
  Building[x][y]->AddNPC(new NPC(s, 1, CurrentState));
}

void GameMain::KivnaSound(int State) {
//sound algorithm
  if (State < 2) {
    Sound = "The facility is eerily quiet. ";
  } else {
    std::string CurrentNoise;
    int difLevel = Mike_Mahon.GetLocationLevel() - Kivna->GetLocationLevel();
    int difPlace = Kivna->GetLocationPlace() - Mike_Mahon.GetLocationPlace();
    // ============= SAME FLOOR ==================
    // ------    Immediate Left   ------------------
    if ((Mike_Mahon.GetLocationLevel() == Kivna->GetLocationLevel())
        && (difPlace == -1)) {
      CurrentNoise = "You hear violent crashing in the room to your left."
          "Robotic noises draw closer and closer to the door. ";
      // ---------- Immediate Right   ------------------
    } else if ((Mike_Mahon.GetLocationLevel() == Kivna->GetLocationLevel())
        && (difPlace == 1)) {
      CurrentNoise = "You hear violent crashing in the room to your right. "
          "Robotic noises draw closer and closer to the door. ";
      // -------------   Left  ------------------
    } else if (Mike_Mahon.GetLocationLevel() == Kivna->GetLocationLevel()
        && (difPlace < -1)) {
      CurrentNoise =
          "You hear heavy stomping somewhere to the left on your floor.";
      // -------------   Right  ------------------
    } else if (Mike_Mahon.GetLocationLevel() == Kivna->GetLocationLevel()
        && (difPlace > 1)) {
      CurrentNoise =
          "You hear heavy stomping somewhere to the right on your floor.";
      // =========== STAIRWAYS =============
    } else if (difLevel == 1 && Kivna->GetLocationPlace() == 4) {
      CurrentNoise = "Mettalic rumbling shakes the floor above you. "
          "You can hear it in the stairwell. ";
    } else if (difLevel == 2 && Kivna->GetLocationPlace() == 4) {
      CurrentNoise = "Mettalic clangs echo throughout the top floor. "
          "You can hear it in the stairwell. ";
    } else if (difLevel == -1 && Kivna->GetLocationPlace() == 4) {
      CurrentNoise = "Mettalic rumbling shakes the floor below you. "
          "You can hear it in the stairwell. ";
    } else if (difLevel == -2 && Kivna->GetLocationPlace() == 4) {
      CurrentNoise = "Mettalic clangs echo throughout the basement. "
          "You can hear it in the stairwell. ";
      // ========== ABOVE ============
    } else if (difLevel == 1 && difPlace < 0) {
      CurrentNoise = "Mettalic rumbling shakes the floor above you. "
          "You can tell it's on the left. ";
    } else if (difLevel == 2 && difPlace < 0) {
      CurrentNoise = "Mettalic clangs echo throughout the top floor. "
          "You can tell it's on the left. ";
    } else if (difLevel == -1 && difPlace > 0) {
      CurrentNoise = "Mettalic rumbling shakes the floor below you. "
          "You can tell it's on the right. ";
    } else if (difLevel == -2 && difPlace > 0) {
      CurrentNoise = "Mettalic clangs echo throughout the basement. "
          "You can tell it's on the right. ";
    } else if (difLevel == 2 && difPlace == 0) {
      CurrentNoise = "Mettalic clangs echo throughout the top floor. "
          "The sound seems to be coming from directly above you. ";
    } else if (difLevel == 1 && difPlace == 0) {
      CurrentNoise = "Mettalic rumbling shakes the floor above you. "
          "The sound seems to be coming from directly above. ";
    } else if (difLevel == -2 && difPlace == 0) {
      CurrentNoise = "Mettalic clangs echo throughout the basement. "
          "The sound seems to be coming from directly below you. ";
    } else if (difLevel == -1 && difPlace == 0) {
      CurrentNoise = "Mettalic rumbling shakes the floor below you. "
          "The sound seems to be coming from directly below. ";
    } else {
      CurrentNoise = "The facility is suspiciously quiet. ";
    }
    Sound = CurrentNoise;
  }
}
