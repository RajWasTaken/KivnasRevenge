/**
 * @author Kaelan Croucher <kaelan.croucher@uleth.ca>
 * @date November 17th, 2022
 */
#ifndef NPC_SCREEN_BUILDER_H
#define NPC_SCREEN_BUILDER_H

#include "InputChecker.h"
#include <iostream>
#include <string>
#include <vector>

/**
 * @class An output formatter for NPC conversations.
 */
class NPCScreenBuilder : public InputChecker {
 public:
  /**
   * @brief Default Constructor.
   */
  NPCScreenBuilder() {
  }
  /**
   * @brief An output formatter for NPC conversations.
   * @details Particularly the possible player inputs.
   * @param The NPC name. 
   * @param  The NPC description. 
   */
  void NPCConvoScreenBuilder(std::string, std::string);
  /**
   * @brief An output formatter for NPC responses to selected player inputs.
   * @param The specific line of dialogue.
   */
  void PrintNPCDialogueToScreen(std::string);
};
#endif // NPC_SCREEN_BUILDER
