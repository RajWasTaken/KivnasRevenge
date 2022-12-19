/**
* @author Kaelan Croucher <kaelan.croucher@uleth.ca>
 * @date December 9th, 2022
 */
#include "InputChecker.h"
#include "NPCScreenBuilder.h"
#include <iostream>
#include <string>
#include <vector>

void NPCScreenBuilder::NPCConvoScreenBuilder(std::string NPCName,
                                             std::string NPCInfo) {
  std::string ConvoScreen = TopLineSpace + BaseIndent;

  ConvoScreen += NPCName + ":" + LineSpace;
  ConvoScreen += StringFormater(NPCInfo) + LineSpace;

  CurrentScreen = ConvoScreen;
}

void NPCScreenBuilder::PrintNPCDialogueToScreen(std::string NPCDialogue) {
  std::string output;
  output += LineSpace + BaseIndent + "Dialogue: " + LineSpace;
  output += StringFormater(NPCDialogue) + "\n";
  std::cout << output << std::endl << std::endl;
}
