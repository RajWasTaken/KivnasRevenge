// Minimal source file that allows the pipeline to pass.
#include "GameMain.h"

int main() {
  bool test = true;
  while (test) {
    GameMain Ethan;
    test = Ethan.StartMenu();
    Ethan.GameLoop();
  }
  return 0;
}
