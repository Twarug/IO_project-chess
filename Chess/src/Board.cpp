#include "Board.h"

#include "Utils.h"

#include <iostream>
#include <algorithm>
#include <vector>

void Board::display() {
    std::vector<Movement> movements = selected ? selected->GetMoves() : std::vector<Movement>();

    int x = 0, y = 0;
    for (auto& row : reverse(board)) {
        ResetCuror({3, 2 + y});
        for (auto piece : row) {
            Pos pos{x, 7 - y};

            // Check if current pos has a possible movement of selected piece
            if (std::find_if(movements.begin(), movements.end(), [pos](const Movement& m){
                return m.pos == pos; 
            }) != movements.end())
                std::cout << "\033[44;1m";

            // Hihglight sleected piece
            if (piece == selected)
                std::cout << "\033[41;1m";

            // Draw piece
            if (piece == nullptr)
                std::cout << ".";
            else
                piece->draw();
            
            std::cout << "\033[0m";
            std::cout << ' ';
            x++;
        }
        y++;
        x = 0;
    }

    std::cout << std::endl;
}

Piece* Board::getPiece(Pos pos) {
    if (pos.x < 0 || pos.x > 7 || pos.y < 0 || pos.y > 7)
        return nullptr;

    return board[pos.y][pos.x];
}

bool Board::selectPiece(Pos pos)
{
    Piece* piece = getPiece(pos);
    if (piece != nullptr) {
        selected = piece;
        return true;
    }
    return false;
}

bool Board::movePiece(Pos pos)
{
    if (selected == nullptr)
        return false;
    
    std::vector<Movement> movements = selected->GetMoves();
    if (std::find_if(movements.begin(), movements.end(), [pos](const Movement& m){ return m.pos == pos; }) == movements.end())
        return false;
    
    Piece* piece = getPiece(pos);

    if (piece != nullptr) {
        //todo: handle taking pieces
    }

    doMove(selected, pos);
    selected = nullptr;

    return true;
}

void Board::doMove(Pos pos1, Pos pos2) {
    Piece* piece = board[pos1.y][pos1.x];
    doMove(piece, pos2);
}

void Board::doMove(Piece* piece, Pos pos) {
    board[piece->pos.y][piece->pos.x] = nullptr;
    board[pos.y][pos.x] = piece;

    piece->pos = pos;
}

Board Board::CreateDefaultBoard()
{
  return Board({{
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
  }});
}
