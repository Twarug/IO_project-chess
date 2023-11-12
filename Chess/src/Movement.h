#pragma once
#include "Pos.h"
#include "Piece.h"

struct Movement
{
  Pos pos;
  Piece& piece;


  Movement(Pos pos, Piece& piece) : pos(pos), piece(piece) {}
};
