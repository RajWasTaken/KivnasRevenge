/**
* @author Kaelan Croucher <kaelan.croucher@uleth.ca>
 * @date December 9th, 2022
 */
#include "InputChecker.h"
#include "ComputerNPCScreenBuilder.h"
#include <iostream>
#include <string>
#include <vector>


void ComputerNPCScreenBuilder::PrintWinScreen() {
  ClearScreen();

  std::string Header = "You successfully debugged the Kivna AI";
  std::string Body = "Dr. Anvik has been restored to human"
      " form and everybody lives happily ever after";

  SpecialScreenBuilder(Header, Body);

  ClearScreen();

  std::string MenuPrompt = "Press any key 1 - 9 to Continue.";
  PrintMenuPrompt(MenuPrompt);
  CheckInput(9);
}


void ComputerNPCScreenBuilder::PrintLossScreen() {
  ClearScreen();

  std::string Header = "You made too many mistakes in debugging the Kivna AI";
  std::string Body = "You watch in horror as robotic tendrils shoot from the"
  " ceiling and pierce themselves into your body. You feel the conciousness "
  "and humanity escape your body and be replaced by a"
  " malevolent, calculating entity.";

  SpecialScreenBuilder(Header, Body);

  ClearScreen();

  std::string MenuPrompt = "Press any key 1 - 9 to Continue.";
  PrintMenuPrompt(MenuPrompt);
  CheckInput(9);
}

void ComputerNPCScreenBuilder::SpecialScreenBuilder(std::string Header,
                                             std::string Body) {
  std::string Screen = LineSpace + LineSpace;
  Screen += StringFormater(Header) + LineSpace;
  Screen += StringFormater(Body) + LineSpace;

  CurrentScreen = Screen;
}
