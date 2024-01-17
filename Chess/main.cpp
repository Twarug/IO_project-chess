#include "src/InputNotationManager.h";
#include "src/Ranking.h";
#include "src/Settings.h"
#include "src/Game.h"

#include <iostream>
#include <string>


InputNotationManager inputNotationManager = InputNotationManager();
Ranking ranking = Ranking("ranking.txt");
Settings settings;

Game* game;

void HandleGameResule(Game::Result result);

int main() {
  std::string input;
  
  do {
    std::cout << "\n\n" << "1) Rozpocznij gre \n";
    std::cout << "2) Wprowadzanie notacji \n";
    std::cout << "3) Ustawienia \n";
    std::cout << "4) Ranking \n";
    std::cout << "q) Wyjdz \n";
    std::cout << "Wybierz: ";
    std::getline(std::cin, input);

    char response = input[0];

    std::cout << input << '\n';

    switch (response) {
      case '1': {
        std::cout << "Rozpocznij gre" << std::endl;
        game = new Game(Board::CreateDefaultBoard());
        Game::Result res = game->Run();
        HandleGameResule(res);
        delete game;

        break;
      }
      case '2': {
        std::cout << "Wprowadzanie notacji" << std::endl;
        Board gameBoard = inputNotationManager.InputManager();
        
        game = new Game(Board::CreateDefaultBoard());
        Game::Result res = game->Run();
        HandleGameResule(res);
        delete game;
        break;
      }
      case '3': {
        std::cout << "Ustawienia" << std::endl;
        settings.PrintSettings();
        break;
      }
      case '4': { 
        std::cout << "Ranking" << std::endl;
        ranking.printManager();
        break;
      }
      default:
      case 'q': {
        break;
      }
    }

  } while(input != "q");

  return 0;
}


void HandleGameResule(Game::Result result) {
  std::cout << "Podaj nick: ";
  std::string nick;
  std::cin >> nick;

  switch (result)
  {
  case Game::Result::WIN:
    ranking.addScore(nick, 1);
    break;
  case Game::Result::LOSE:
    ranking.addScore(nick, 0);
    break;
  case Game::Result::DRAW:
    ranking.addScore(nick, 0.5);
    break;
  default:
    break;
  }
}