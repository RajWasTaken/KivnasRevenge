/**
* @author Kaelan Croucher <kaelan.croucher@uleth.ca>
 * @date December 9th, 2022
 */
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include "ComputerNPC.h"
#include "NPCScreenBuilder.h"
#include "NPC.h"

ComputerNPC::ComputerNPC(std::string a, int b, int c)
    :
    NPC(a, b, c) {
  std::string NameF, DescF, EntryF, Blank;
  std::string files[4] = { "./docs/QuizQuestions/Q1", "./docs/QuizQuestions/Q2",
      "./docs/QuizQuestions/Q3", "./docs/QuizQuestions/Q4" };
  std::ifstream FileReader;
  FileReader.open("./docs/ComputerQuestions");

  for (int i = 0; i < 4; i++) {
    question[i] = ReadQuestion(files[i]);
  }
  std::getline(FileReader, NameF);
  name = NameF;
  std::getline(FileReader, DescF);
  description = DescF;
  std::getline(FileReader, EntryF);
  entryconvo = EntryF;

  for (int j = 0; j < 4; j++) {
    std::getline(FileReader, Blank);
    for (int k = 0; k < 4; k++) {
      std::getline(FileReader, ansarr[k][j]);
    }
  }
}

bool ComputerNPC::HasPassed() {
  return NumCorrect >= 3;
}

bool ComputerNPC::HasFailed() {
  return (NumCorrect < 3 && Attempts > 1);
}
void ComputerNPC::ConvoOut(int i) {
  bool DebugEnd = false;
  while (!DebugEnd) {
    for (int i = 0; i < 4; i++) {
      MenuUtil.ClearScreen();
      MenuUtil.PrintMenuPrompt(question[i]);
      MenuUtil.PrintMenuPrompt("What is the outcome of this code.");
      MenuUtil.PrintMenuPrompt("1. " + ansarr[0][i]);
      MenuUtil.PrintMenuPrompt("2. " + ansarr[1][i]);
      MenuUtil.PrintMenuPrompt("3. " + ansarr[2][i]);

      std::string SelectedOption = ansarr[MenuUtil.CheckInput(3) - 1][i];
      if (ansarr[3][i] == SelectedOption) {
        NumCorrect++;
      }
      DebugEnd = true;
    }
  }
}

int ComputerNPC::WinCondition() {
  if (NumCorrect > 1) {
    SpecialEventFlag = 2;
    MenuUtil.PrintWinScreen();
  } else if (NumCorrect < 2 && NumCorrect >= 0) {
    MenuUtil.PrintLossScreen();
    SpecialEventFlag = 1;
  } else {
    SpecialEventFlag = 0;
  }
  return SpecialEventFlag;
}

bool ComputerNPC::GetTalking() {
  if (NumCorrect > 2) {
    return true;
  } else {
    return false;
  }
}

std::string ComputerNPC::ReadQuestion(std::string File) {
  std::ifstream RCule;
  RCule.open(File);
  std::vector < std::string > Question;
  std::string QuestionHolder;
  for (int i = 0; i < 13; i++) {
    std::getline(RCule, QuestionHolder);
    Question.push_back(QuestionHolder);
  }

  RCule.close();

  std::string Padding = "          ";
  std::string Output = "\n\n\n\n";
  for (int i = 0; i < Question.size(); i++) {
    std::string ConcatString = Padding + Question[i] + "\n";
    Output += ConcatString;
  }
  Output += "\n\n\n";
  return Output;
}
