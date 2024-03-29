#include "Game.h"

#include "Utils.h"

#include <iostream>

Game::Result Game::Run() {
  try {
    Init();
    
    // Game loop
    while (m_isRunning) {
      Update();
      Render();
    }

    Cleanup();
  } catch(...) {
    return Result::ERR;
  }

  return m_result;
}

void Game::Init() {
  std::system("cls");
  ResetCuror({0, 0});

  std::cout << "   ";
  for(int i = 0; i < 8; i++)
    std::cout << (char)('A' + i) << ' ';
  std::cout << '\n';

  for(int i = 0; i < 8; i++)
    std::cout << '\n' << 8 - i << ' ' << std::string(18, ' ') << 8 - i;

  std::cout << "\n\n   ";
  for(int i = 0; i < 8; i++)
    std::cout << (char)('A' + i) << " ";

  std::cout << std::string('\n', 4);

  Render();
}

void Game::Update() {
  for(;;) {
    ResetCuror({0, 14});
    std::cout << std::string(100, ' ');
    ResetCuror({0, 14});
    std::cout << "Wybierz pionek: " ;

    Piece* selected = m_board.getSelected();
    if (selected != nullptr)
      std::cout << (char)(selected->GetPos().x + 'A') << selected->GetPos().y + 1 << " -> ";

    std::string input;
    std::cin >> input;

    if (!selected && input.length() > 3 && input == std::string(input.length(), 'q')) {
      m_isRunning = false;
      m_result = Result::LOSE;
      break;
    }

    if (input[0] == 'q') {
      m_board.unselectPiece();
      break;
    }

    if (input.length() != 2) {
      // Niepoprawna pozycja
      continue;
    }

    if (selected != nullptr) {
      // Ruch
      Pos pos = Pos(input[0] < 'Z' ? input[0] - 'A' : input[0] - 'a', input[1] - '1');
      if (m_board.movePiece(pos))
        break;
    } else {
      // Wybor pionka
      Pos pos = Pos(input[0] < 'Z' ? input[0] - 'A' : input[0] - 'a', input[1] - '1');
      if(m_board.selectPiece(pos))
        break;
    }
  }
}

void Game::Render() {
  m_board.display();
}

void Game::Cleanup() {
  ResetCuror({0, 20});
  std::system("PAUSE");
  std::system("cls");
}



/* ********
   ********
   ********
   ********
   ********
   ********
   ******** */
