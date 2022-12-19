/**
* @author Kaelan Croucher <kaelan.croucher@uleth.ca>
 * @date December 9th, 2022
 */
#ifndef INPUT_CHECKER
#define INPUT_CHECKER

#include <iostream>
#include <string>
#include <vector>

/**
 * @class InputChecker InputChecker.h "InputChecker.h"
 * @brief Baseclass of InputChecker.
 */
class InputChecker {
 public:
  /**
    * @brief  Default Constructor of InputChecker
    * @details Default Constructor of InputChecker
    */
  InputChecker() {
  }
  /**
    * @brief Accpets int and then prompts player for input.
    * @details Accpets int and Prompts player for input,
    * error check to ensure input is within maximum range
    * @param[in] Int to determine maximum range of allowed input.
    */
  int CheckInput(int);

  /**
    * @brief Clears screen
    * @details Clears screen and prints the
    * last screen that was stored..
    */
  void ClearScreen();

  /**
    * @brief Genereic function prints string to screen.
    * @details Formats and prints string to screen.
    * @param[in] string to be formatted then printed to screen.
    */
  void PrintMenuPrompt(std::string);

  /**
    * @brief Prints last screen to console..
    * @details prints the CurrentString to console.
    */
  void PrintCurrentScreen();

  /**
    * @brief Accepts a string and formats it to string.
    * @details Formats string to fit the rest of the menu style.
    * @param[in] string to be formatted
    */
  std::string StringFormater(std::string);

  /**
    * @brief Formats the top part of the menu display.
    * @details Formats the top Floor and Room Attributes
    *  in a line and returns them as an output.
    * @param[in] int value to determine the floor the player is on.
    * @param[in] string value to determine the room the player is on.
    */
  std::string StatusBarFormater(int, std::string);

  /**<CurrentScreen for storing the elements most recently printed to screen*/
  std::string CurrentScreen;

  /**<LastMenu stores the most recent menu section of the screen.*/
  std::string LastMenu;

  /**<BaseIndent string used for formatting*/
  std::string BaseIndent = "                    ";

  /**<DescIndent string used for formatting*/
  std::string DescIndent = "                         ";

  /**<TopLineSpace string used for formatting*/
  std::string TopLineSpace = "\n\n\n\n\n\n";

  /**<LineSpace string used for formatting*/
  std::string LineSpace = "\n\n";
};
#endif //INPUT_CHECKER
