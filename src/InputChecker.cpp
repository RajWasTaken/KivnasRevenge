/**
* @author Kaelan Croucher <kaelan.croucher@uleth.ca>
 * @date December 9th, 2022
 */
#include "InputChecker.h"
#include <iostream>
#include <string>
#include <vector>

int InputChecker::CheckInput(int MaxSelect) {
  std::string str_input = "";
  int input;

  std::cout << StringFormater("Selection: ");
  std::cin >> str_input;
  input = str_input[0] - '0';

  while (1 > input || input > MaxSelect) {
    ClearScreen();
    std::cout << LastMenu;
    std::string InvalidPrompt = "Invalid entry please select a value"
        " between 1 and " + std::to_string(MaxSelect);
    std::cout << StringFormater(InvalidPrompt) << std::endl << std::endl;
    std::cout << StringFormater("Selection: ");
    std::cin >> str_input;
    input = str_input[0] - '0';
  }
  LastMenu = "";
  return input;
}

void InputChecker::ClearScreen() {
  system("clear");
  PrintCurrentScreen();
}

void InputChecker::PrintCurrentScreen() {
  std::cout << CurrentScreen;
}

void InputChecker::PrintMenuPrompt(std::string MenuPrompt) {
  MenuPrompt = StringFormater(MenuPrompt);
  LastMenu += MenuPrompt + "\n\n";
  std::cout << MenuPrompt << std::endl << std::endl;
}

std::string InputChecker::StringFormater(std::string Input) {
  std::string Output = DescIndent;
  std::string OverFlow;

  if (Input.length() > 70) {
    int stringIter = 0;
    for (int i = 0; i < 70; i++) {
      while (i == 69) {
        char currentChar = Input[stringIter];
        if (currentChar == ' ') {
          Output += " \n";
          while (stringIter < Input.length()) {
            OverFlow += Input[stringIter];
            stringIter++;
          }
          Output += StringFormater(OverFlow);
          break;
        }
        Output += Input[stringIter];
        stringIter++;
      }
      Output += Input[stringIter];
      stringIter++;
    }
    return Output;
  } else {
    int Padding = (70 - Input.length()) / 2;
    for (int i = 0; i < Padding; i++) {
      Output += " ";
    }
    Output += Input;
    return Output;
  }
}

std::string InputChecker::StatusBarFormater(int FloorNum,
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
