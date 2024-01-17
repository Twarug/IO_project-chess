#pragma once
#include "Pos.h"

class Piece;

struct Movement
{
  Pos pos;
  Piece& piece;


  Movement(Pos pos, Piece& piece) : pos(pos), piece(piece) {}

  class Builder {
    Pos pos;
    Piece* piece;

  public:
    Builder& SetPos(Pos pos) { this->pos = pos; return *this; }
    Builder& SetPiece(Piece& piece) { this->piece = &piece; return *this; }

    Movement Build() {
      return { pos, *piece };
    }
  };
};
