#pragma once
#include "Pos.h"

class Piece;

struct Movement
{
  Pos pos;
  Piece& piece;


  Movement(Pos pos, Piece& piece) : pos(pos), piece(piece) {}
};
