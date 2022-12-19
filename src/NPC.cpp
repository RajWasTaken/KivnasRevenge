/**
* @author Kaelan Croucher <kaelan.croucher@uleth.ca>
 * @date December 9th, 2022
 */
#include <string>
#include <iostream>
#include "NPC.h"
#include "fstream"

NPC::NPC(std::string location, int DialogueChanges, int CurrentState) {
  currentState = CurrentState;
  std::ifstream convo;
  std::string NameF, DescF, EntryF, Blank;
  convo.open(location);
  if (convo) {
    std::getline(convo, NameF);
    name = NameF;
    std::getline(convo, DescF);
    description = DescF;
    std::getline(convo, EntryF);
    entryconvo = EntryF;
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 3; j++) {
        std::getline(convo, Blank);
        std::getline(convo, Blank);
        std::getline(convo, Blank);
        for (int k = 0; k < 3; k++) {
          std::getline(convo, npcdialogue[i][j][k]);
        }
      }
    }

    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 3; j++) {
        std::getline(convo, Blank);
        std::getline(convo, Blank);
        std::getline(convo, Blank);
        for (int k = 0; k < 3; k++) {
          std::getline(convo, playerresponse[i][j][k]);
        }
      }
    }
    dead = false;
  } else {
    std::cout << "file does not exist" << std::endl;
  }
  convo.close();
}

std::string NPC::GetName() {
  return name;
}

void NPC::ConvoOut(int i) {
  bool ExitLoop = false;
  std::string currentConvOut = "";
  int StoryConvo = 0;
  int ObjConvo = 0;
  int CharConvo = 0;

  screenbuilder.NPCConvoScreenBuilder(name, description);

  while (ExitLoop == false) {
    screenbuilder.ClearScreen();
    if (currentConvOut != "") {
      screenbuilder.PrintNPCDialogueToScreen(currentConvOut);
    }
    screenbuilder.PrintMenuPrompt("What would you like"
        " to say to " + name + "? ");

    screenbuilder.PrintMenuPrompt(
        "1. " + playerresponse[currentState][0][StoryConvo]);
    screenbuilder.PrintMenuPrompt(
        "2. " + playerresponse[currentState][1][ObjConvo]);
    screenbuilder.PrintMenuPrompt(
        "3. " + playerresponse[currentState][2][CharConvo]);
    screenbuilder.PrintMenuPrompt("4. Stop Talking to " + name);

    int input = screenbuilder.CheckInput(4);
    switch (input) {
      case 1:
        currentConvOut = npcdialogue[currentState][0][StoryConvo];
        if (StoryConvo == 2) {
          StoryConvo = 0;
        } else {
          StoryConvo++;
        }
        break;
      case 2: {
        currentConvOut = npcdialogue[currentState][1][ObjConvo];
        if (ObjConvo == 2) {
          ObjConvo = 0;
        } else {
          TalkedThisState = true;
          ObjConvo++;
        }
        break;
      }
      case 3: {
        currentConvOut = npcdialogue[currentState][2][CharConvo];
        if (CharConvo == 2) {
          CharConvo = 0;
        } else {
          CharConvo++;
        }
        break;
      }
      case 4:
        ExitLoop = true;
        break;
    }
  }
}

bool NPC::GetDeath() {
  return dead;
}

void NPC::SetDeath(bool d) {
  dead = d;
}

bool NPC::GetTalking() {
  return TalkedThisState;
}

void NPC::SetTalkedThisState() {
  currentState++;
  TalkedThisState = false;
}
