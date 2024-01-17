#pragma once
#include <cstdint>

#include "Color.h"
#include "Board.h"

class Game {
public:
  enum class Result : uint8_t {
    WIN, LOSE, DRAW,
    ERR,
  };

  bool m_isRunning = true;
  Color m_currentPlayer = Color::WHITE;

  Board m_board;

public:
  Game(Board board) : m_board(std::move(board)) {}

  Result Run();

private:
  void Init();
  void Update();
  void Render();
  void Cleanup();
};