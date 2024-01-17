#include "src/InputNotationManager.h";
#include "src/Ranking.h";
#include "src/Board.h"
#include "src/Settings.h"

#include <iostream>

int main() {
  Ranking *ranking = new Ranking("ranking.txt");

  Settings settings;
  settings.PrintSettings();
  settings.ChangeSettings();
  settings.PrintSettings();

  InputNotationManager *inputNotationManager = new InputNotationManager();
  // ranking->printManager();
  bool startGame = inputNotationManager->InputManager();

  if (startGame == true)
    std::cout << "Game starts" << std::endl;

  board.display();

  return 0;
}