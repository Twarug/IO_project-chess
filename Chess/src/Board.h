#pragma once

#include "Piece.h"

#include <array>


class Board {
public:
  using BoardArray = std::array<std::array<Piece*, 8>, 8>;
private:

  BoardArray board;

  Piece* selected = nullptr;

public:
  Board(BoardArray board) : board(board) {}

  void display();

  Piece* getPiece(Pos pos);

  Piece* getSelected() { return selected; }
  void unselectPiece() { selected = nullptr; }
  bool selectPiece(Pos pos);

  bool movePiece(Pos pos);

private:
  void doMove(Pos pos1, Pos pos2);
  void doMove(Piece* piece, Pos pos);

public:
  static Board CreateDefaultBoard();
};