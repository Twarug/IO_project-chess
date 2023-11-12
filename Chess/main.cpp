#include <iostream>

#include "src/Board.h"
#include "src/Settings.h"

Board board;

int main() {
  Settings settings;

  std::cout << "Hello, World!" << std::endl;

  settings.PrintSettings();

  settings.ChangeSettings();

  settings.PrintSettings();

  // settings.ResetSettings();

  // settings.PrintSettings();
}