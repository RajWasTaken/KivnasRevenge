/**
* @author Kaelan Croucher <kaelan.croucher@uleth.ca>
 * @date December 9th, 2022
 */
#ifndef MAIN_SCREEN_BUILDER_H
#define MAIN_SCREEN_BUILDER_H

#include "InputChecker.h"
#include "Rooms.h"
#include <iostream>
#include <string>
#include <vector>

/**
 * @class NPC NPC.h "NPC.h"
 * @brief Baseclass of NPC.a.
 */
class MainScreenBuilder : public InputChecker {
 public:
  MainScreenBuilder();
  /**
    * @brief Returns a bool set within the class..
    * @details Returns bool based on whether or not a
    * player has talked to the npc this turn.
    */
  void SpecialScreenBuilder(std::string, std::string);
  void GameScreenBuilder(int, std::string, std::string, std::string,
                         std::string);
  void StartScreenBuilder(std::vector<std::string>);

  /**
    * @brief Returns a bool set within the class..
    * @details Returns bool based on whether or not a
    * player has talked to the npc this turn.
    */
  int PrintStartMenu();

  /**
    * @brief Returns a bool set within the class..
    * @details Returns bool based on whether or not a
    * player has talked to the npc this turn.
    */
  int PrintPauseMenu();

  /**
    * @brief Returns a bool set within the class..
    * @details Returns bool based on whether or not a
    * player has talked to the npc this turn.
    */
  void PrintInstructScreen();

  /**
    * @brief Returns a bool set within the class..
    * @details Returns bool based on whether or not a
    * player has talked to the npc this turn.
    */
  int PrintMainMenu(int, bool, std::string, int);

  /**
    * @brief Returns a bool set within the class..
    * @details Returns bool based on whether or not a
    * player has talked to the npc this turn.
    */
  void PrintStateScreen(int);

  /**
    * @brief Returns a bool set within the class..
    * @details Returns bool based on whether or not a
    * player has talked to the npc this turn.
    */
  int PrintMoveMenu(std::string);

  /**
    * @brief Returns a bool set within the class..
    * @details Returns bool based on whether or not a
    * player has talked to the npc this turn.
    */
  int PrintItemsToScreen();

  /**
    * @brief Returns a bool set within the class..
    * @details Returns bool based on whether or not a
    * player has talked to the npc this turn.
    */
  void PrintDeathScreen();

  /**
    * @brief Returns a bool set within the class..
    * @details Returns bool based on whether or not a
    * player has talked to the npc this turn.
    */
  void PrintHelpScreen();

  /**
    * @brief Returns a bool set within the class..
    * @details Returns bool based on whether or not a
    * player has talked to the npc this turn.
    */
  void PrintPrologueScreen();

  /**
    * @brief Returns a bool set within the class..
    * @details Returns bool based on whether or not a
    * player has talked to the npc this turn.
    */
  void PrintWinScreen();

  /**
    * @brief Returns a bool set within the class..
    * @details Returns bool based on whether or not a
    * player has talked to the npc this turn.
    */
  void PrintLossScreen();

  /**
    * @brief Returns a bool set within the class..
    * @details Returns bool based on whether or not a
    * player has talked to the npc this turn.
    */
  void PrintExtraScreen(std::string, std::string);

 private:
  /**
    * @brief Returns a bool set within the class..
    * @details Returns bool based on whether or not a
    * player has talked to the npc this turn.
    */
  void PrintMapArray();

  /**
    * @brief Returns a bool set within the class..
    * @details Returns bool based on whether or not a
    * player has talked to the npc this turn.
    */
  void BuildStateScreenArrays(std::string);

  /**
    * @brief Returns a bool set within the class..
    * @details Returns bool based on whether or not a
    * player has talked to the npc this turn.
    */
  std::string StatusBarFormater(int, std::string);

  /**<name for storing NPC's string*/
  std::vector<std::string> StartLogo;

  /**<name for storing NPC's string*/
  std::vector<std::string> MapOfLab;

  /**<name for storing NPC's string*/
  std::string StateHeaders[12];

  /**<name for storing NPC's string*/
  std::string StateDescs[12];
};
#endif // MAIN_SCREEN_BUILDER
