#pragma once

#include "Piece.h"

#include <array>


class Board {
  std::array<std::array<Piece*, 8>, 8> board;

public:
  void display();
};