#include "InputChecker.h"
#include "MainScreenBuilder.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

MainScreenBuilder::MainScreenBuilder() {
  std::ifstream RCule;
  RCule.open("./docs/kivnalogo.txt");
  std::string LogoHolder;
  for (int i = 0; i < 17; i++) {
    std::getline(RCule, LogoHolder);
    StartLogo.push_back(LogoHolder);
  }
  RCule.close();

  RCule.open("./docs/Map.txt");
  for (int i = 0; i < 8; i++) {
    std::getline(RCule, LogoHolder);
    MapOfLab.push_back(LogoHolder);
  }
  RCule.close();

  BuildStateScreenArrays("./docs/StateScreens.txt");
}

void MainScreenBuilder::GameScreenBuilder(int Floor, std::string RoomName,
                                          std::string RoomDesc,
                                          std::string Objective,
                                          std::string Sound) {
  RoomDesc = StringFormater(RoomDesc);
  Objective = StringFormater("Objective: " + Objective);
  std::string StatusBar = StatusBarFormater(Floor, RoomName);
  std::string SoundStatus = StringFormater("Sound: " + Sound);

  std::string Screen = TopLineSpace + StatusBar + LineSpace + Objective
      + LineSpace + SoundStatus + LineSpace + BaseIndent + "Description: \n\n"
      + RoomDesc + LineSpace + "\n";
  CurrentScreen = Screen;
}

void MainScreenBuilder::SpecialScreenBuilder(std::string Header,
                                             std::string Body) {
  std::string Screen = LineSpace + LineSpace;
  Screen += StringFormater(Header) + LineSpace;
  Screen += StringFormater(Body) + LineSpace;

  CurrentScreen = Screen;
}

std::string MainScreenBuilder::StatusBarFormater(int FloorNum,
                                                 std::string RoomName) {
  std::string FloorString;

  switch (FloorNum) {
    case 0:
      FloorString = "Upstairs";
      break;

    case 1:
      FloorString = "Main Floor";
      break;

    case 2:
      FloorString = "Basement";
      break;
  }
  std::string FloorTag = "Floor: " + FloorString;
  std::string RoomTag = "Room: " + RoomName;

  int MiddleSpacer = 65 - (FloorTag.length() + RoomTag.length());

  std::string StatusBar = FloorTag;

  for (int i = 0; i < MiddleSpacer; i++) {
    StatusBar += " ";
  }
  StatusBar += RoomTag;

  return StringFormater(StatusBar);
}

void MainScreenBuilder::StartScreenBuilder(std::vector<std::string> Logo) {
  std::string Padding = "          ";
  std::string Output = TopLineSpace;
  for (int i = 0; i < Logo.size(); i++) {
    std::string ConcatString = Padding + Logo[i] + "\n";
    Output += ConcatString;
  }
  Output += LineSpace;
  CurrentScreen = Output;
}

int MainScreenBuilder::PrintMainMenu(int RoomType, bool IsSearched,
                                     std::string NPCName, int State) {
  ClearScreen();
  int selection;
  int i = 3;

  PrintMenuPrompt("What would you like to do?");

  std::string SearchOrPick;
  if (IsSearched) {
    SearchOrPick = "Pick Up Item";
  } else {
    SearchOrPick = "Search the Room";
  }

  std::string MenuOpt = "1. " + SearchOrPick + "     2. Move";
  PrintMenuPrompt(MenuOpt);

  if (RoomType != 0) {
    switch (RoomType) {
      case 1: {
        break;
      }
      case 2: {
        if (IsSearched && State < 5) {
          MenuOpt = std::to_string(i) + ". Flip the Breaker On.";
          PrintMenuPrompt(MenuOpt);
          i++;
          break;
        } else if (IsSearched && State > 10) {
          MenuOpt = std::to_string(i) + ". Set Bomb in Furnace.";
          PrintMenuPrompt(MenuOpt);
          i++;
          break;
        } else {
          break;
        }
      }
      case 3: {
        MenuOpt = std::to_string(i) + ". Talk To " + NPCName;
        PrintMenuPrompt(MenuOpt);
        i++;
        break;
      }
    }
  }

  PrintMenuPrompt(
      std::to_string(i) + ". Inventory     " + std::to_string(i + 1) + ". Map");
  i++;

  int RawInput = CheckInput(i);

  if (IsSearched && selection == 1) {
    //Selection 5 will be for Pick up 5 menu.
    selection = 6;
  }
  if (RawInput > 2 && RoomType > 0) {
    if (RawInput == 3) {
      selection = 5;
    } else if (RawInput == 4) {
      selection = 3;
    } else if (RawInput == 5) {
      selection = 4;
    }
  } else {
    selection = RawInput;
  }

  return selection;
}

int MainScreenBuilder::PrintPauseMenu() {
  int PauseSelect;
  bool ResumeGame = false;

  while (!ResumeGame) {
    PrintMapArray();
    ClearScreen();
    PrintMenuPrompt("||Paused||");
    PrintMenuPrompt("1. Resume   2. Help");
    PrintMenuPrompt("3. Quit Game");
    int MenuAction = CheckInput(3);

    switch (MenuAction) {
      case 1:
        ResumeGame = true;
        PauseSelect = 1;
        break;

      case 2:
        PrintHelpScreen();
        break;

      case 3:
        ClearScreen();
        PrintMenuPrompt("Are you sure you would like to quit?");
        PrintMenuPrompt("1. Yes    2. No");

        int QuitAction = CheckInput(2);

        if (QuitAction == 1) {
          PauseSelect = 2;
          ResumeGame = true;
        }
        break;
    }
  }
  return PauseSelect;
}

int MainScreenBuilder::PrintStartMenu() {
  StartScreenBuilder(StartLogo);
  ClearScreen();
  std::string MenuOpt1 = "1. Start Game";
  std::string MenuOpt2 = "2. About";
  std::string MenuOpt3 = "3. Quit";

  PrintMenuPrompt(MenuOpt1);
  PrintMenuPrompt(MenuOpt2);
  PrintMenuPrompt(MenuOpt3);

  return CheckInput(3);
}

void MainScreenBuilder::PrintExtraScreen(std::string head, std::string body) {
  ClearScreen();

  std::string Header = head;
  std::string Body = body;

  SpecialScreenBuilder(Header, Body);

  ClearScreen();

  std::string MenuPrompt = "Press any key 1 - 9 to Continue.";
  PrintMenuPrompt(MenuPrompt);
  CheckInput(9);
}

void MainScreenBuilder::PrintDeathScreen() {
  ClearScreen();

  std::string Header = "You Are Dead";
  std::string Body = "Kivna has caught you. How very sad.";

  SpecialScreenBuilder(Header, Body);

  ClearScreen();

  std::string MenuPrompt = "Press any key 1 - 9 to Exit.";
  PrintMenuPrompt(MenuPrompt);
  CheckInput(9);
}

void MainScreenBuilder::PrintInstructScreen() {
  std::string Header = "Welcome To Kivna's Revenge.";
  std::string Body = "At any time you can look at your inventory, interact "
      "with your room, or get help from here. Any physical "
      "action can cause reactions from the game world and "
      "will end your turn. In any given room you may be able to"
      " look around for clues, search for goodies, pick up said goodies, and "
      "interact with specific things. Feel free to explore your environment "
      "and move around. Be careful though - some things may be noisier than "
      "others.";
  SpecialScreenBuilder(Header, Body);
  ClearScreen();

  std::string MenuOpt = "Press any key 1 - 9 to go back.";
  PrintMenuPrompt(MenuOpt);
  CheckInput(9);
  CurrentScreen = " ";
  ClearScreen();
}

void MainScreenBuilder::PrintStateScreen(int State) {
  std::string Header = StateHeaders[State];
  //StateHeaders[State - 1];
  std::string Body = StateDescs[State];
  //StateDescs[State - 1];

  SpecialScreenBuilder(Header, Body);
  ClearScreen();

  std::string MenuOpt = "Press any key 1 - 9 to go Continue";
  PrintMenuPrompt(MenuOpt);
  CheckInput(9);
  CurrentScreen = " ";
  ClearScreen();
}

void MainScreenBuilder::BuildStateScreenArrays(std::string File) {
  std::ifstream RCule;
  std::string GetBlank;
  RCule.open("./docs/StateScreens.txt");
  for (int i = 0; i < 13; i++) {
    std::getline(RCule, GetBlank);
    std::getline(RCule, StateHeaders[i]);
    std::getline(RCule, GetBlank);
    std::getline(RCule, StateDescs[i]);
  }
  RCule.close();
}

void MainScreenBuilder::PrintMapArray() {
  std::string output = "\n\n\n\n\n\n";
  for (int i = 0; i < 8; i++) {
    output += "             " + MapOfLab[i] + "\n";
  }
  CurrentScreen = output + "\n\n";
}

void MainScreenBuilder::PrintHelpScreen() {
  ClearScreen();

  std::string Header = "Help:";
  std::string Body = "Any time you move search or Pick up and item you the "
      "world moves around you, your goal"
      " is to complete the on screen objective without "
      "running into KIVNA. ";

  SpecialScreenBuilder(Header, Body);

  ClearScreen();

  std::string MenuPrompt = "Press any key 1 - 9 to Exit.";
  PrintMenuPrompt(MenuPrompt);
  CheckInput(9);
}

void MainScreenBuilder::PrintPrologueScreen() {
  ClearScreen();

  std::string Header = "After a 3 hour drive into the mountains,"
                      " you finally reach your internship site. ";
  std::string Body = "You hesitantly grab your luggage and thank the driver."
      " Long summer ahead eh? he says. Yeah you reply, in a half chuckle half"
      " sigh. As you arrive at the front door of the facility,"
      " you see lights flickering in the upstairs windows."
      " After you ring the doorbell, a voice cracks over the loudspeaker."
      " Oh you're finally here. Head inside and go talk"
      "to Dr. Anvik. He's in the upstairs lab. The stairs"
      " are all the way to the right. ";

  SpecialScreenBuilder(Header, Body);

  ClearScreen();

  std::string MenuPrompt = "Press any key 1 - 9 to Continue.";
  PrintMenuPrompt(MenuPrompt);
  CheckInput(9);
}
