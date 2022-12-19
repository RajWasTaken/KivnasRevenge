/**
* @author Kaelan Croucher <kaelan.croucher@uleth.ca>
* @date November 17th, 2022
*/
#ifndef COMPUTER_NPC_SCREEN_BUILDER_H
#define COMPUTER_NPC_SCREEN_BUILDER_H

#include <iostream>
#include <string>
#include <vector>

/**
 * @class ComputerNPCScreenBuilder ComputerNPCScreenBuilder.h
 *  "ComputerNPCScreenBuilder.h"
 * @brief Inheriting class of InputChecker.
 */
class ComputerNPCScreenBuilder : public InputChecker {
 public:
  /**
    * @brief Formats two strings to be formatted to screen.
    * @details Accepts two strings and formats them to be printed.
    * @param[in] string header, string to be formatted.
    * @param[in] string body, string to be formatted.
    */
  void SpecialScreenBuilder(std::string, std::string);

  /**
    * @brief Prints a screen for win conditions.
    * @details Prints the win conditions for the debug stage.
    */
  void PrintWinScreen();

  /**
    * @brief Prints Screen based on loss conditions.
    * @details Prints loss conditions based on debugs.
    */
  void PrintLossScreen();
};
#endif //INPUT_CHECKER
