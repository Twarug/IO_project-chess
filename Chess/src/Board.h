#pragma once

#include "Piece.h"

#include <array>


class Board {
  std::array<std::array<Piece*, 8>, 8> board = {{
    {{
      new Rook({0, 0}, Color::WHITE),
      new Knight({1, 0}, Color::WHITE),
      new Bishop({2, 0}, Color::WHITE),
      new Queen({3, 0}, Color::WHITE),
      new King({4, 0}, Color::WHITE),
      new Bishop({5, 0}, Color::WHITE),
      new Knight({6, 0}, Color::WHITE),
      new Rook({7, 0}, Color::WHITE),
    }},
    {{
      new Pawn({0, 1}, Color::WHITE),
      new Pawn({1, 1}, Color::WHITE),
      new Pawn({2, 1}, Color::WHITE),
      new Pawn({3, 1}, Color::WHITE),
      new Pawn({4, 1}, Color::WHITE),
      new Pawn({5, 1}, Color::WHITE),
      new Pawn({6, 1}, Color::WHITE),
      new Pawn({7, 1}, Color::WHITE),
    }},
    {{
      nullptr,
      nullptr,
      nullptr,
      nullptr,
      nullptr,
      nullptr,
      nullptr,
      nullptr,
    }},
    {{
      nullptr,
      nullptr,
      nullptr,
      nullptr,
      nullptr,
      nullptr,
      nullptr,
      nullptr,
    }},
    {{
      nullptr,
      nullptr,
      nullptr,
      nullptr,
      nullptr,
      nullptr,
      nullptr,
      nullptr,
    }},
    {{
      nullptr,
      nullptr,
      nullptr,
      nullptr,
      nullptr,
      nullptr,
      nullptr,
      nullptr,
    }},
    {{
      new Pawn({0, 6}, Color::BLACK),
      new Pawn({1, 6}, Color::BLACK),
      new Pawn({2, 6}, Color::BLACK),
      new Pawn({3, 6}, Color::BLACK),
      new Pawn({4, 6}, Color::BLACK),
      new Pawn({5, 6}, Color::BLACK),
      new Pawn({6, 6}, Color::BLACK),
      new Pawn({7, 6}, Color::BLACK),
    }},
    {{
      new Rook({0, 7}, Color::BLACK),
      new Knight({1, 7}, Color::BLACK),
      new Bishop({2, 7}, Color::BLACK),
      new Queen({3, 7}, Color::BLACK),
      new King({4, 7}, Color::BLACK),
      new Bishop({5, 7}, Color::BLACK),
      new Knight({6, 7}, Color::BLACK),
      new Rook({7, 7}, Color::BLACK),
    }},
  }};

  Piece* selected = board[0][6];

public:
  void display();
};