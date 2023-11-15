#include "Piece.h"

#include <iostream>

void EmplaceMovement(std::vector<Movement>& moves, Pos pos, Piece& piece) {
    if (pos.x >= 0 && pos.x < 8 && pos.y >= 0 && pos.y < 8) {
        moves.emplace_back(pos, piece);
    }
}

void Pawn::draw() {
    std::cout << "P";
}

std::vector<Movement> Pawn::GetMoves() {
    std::vector<Movement> moves;
    if (this->color == Color::WHITE) {
        EmplaceMovement(moves, Pos(this->pos.x, this->pos.y + 1), *this);
    } else {
        EmplaceMovement(moves, Pos(this->pos.x, this->pos.y - 1), *this);
    }
    return moves;
}

void Rook::draw() {
    std::cout << "R";
}

std::vector<Movement> Rook::GetMoves() {
    std::vector<Movement> moves;
    for (int i = 0; i < 8; ++i) {
        if (i != pos.y)
            EmplaceMovement(moves, Pos(i, this->pos.y), *this);
        
        if (i != pos.x)
            EmplaceMovement(moves, Pos(this->pos.x, i), *this);
    }
    return moves;
}

void Knight::draw() {
    std::cout << "N";
}

std::vector<Movement> Knight::GetMoves() {
    std::vector<Movement> moves;
    EmplaceMovement(moves, Pos(this->pos.x + 2, this->pos.y + 1), *this);
    EmplaceMovement(moves, Pos(this->pos.x + 2, this->pos.y - 1), *this);
    EmplaceMovement(moves, Pos(this->pos.x - 2, this->pos.y + 1), *this);
    EmplaceMovement(moves, Pos(this->pos.x - 2, this->pos.y - 1), *this);
    EmplaceMovement(moves, Pos(this->pos.x + 1, this->pos.y + 2), *this);
    EmplaceMovement(moves, Pos(this->pos.x + 1, this->pos.y - 2), *this);
    EmplaceMovement(moves, Pos(this->pos.x - 1, this->pos.y + 2), *this);
    EmplaceMovement(moves, Pos(this->pos.x - 1, this->pos.y - 2), *this);
    return moves;
}

void Bishop::draw() {
    std::cout << "B";
}

std::vector<Movement> Bishop::GetMoves() {
    std::vector<Movement> moves;
    for (int i = 1; i < 8; ++i) {
        EmplaceMovement(moves, pos + Pos(i, i), *this);
        EmplaceMovement(moves, pos + Pos(i, -i), *this);
        EmplaceMovement(moves, pos + Pos(-i, i), *this);
        EmplaceMovement(moves, pos + Pos(-i, -i), *this);
    }
    return moves;
}

void Queen::draw() {
    std::cout << "Q";
}

std::vector<Movement> Queen::GetMoves() {
    std::vector<Movement> moves;
    for (int i = 0; i < 8; ++i) {
        if (i != pos.y)
            EmplaceMovement(moves, Pos(i, this->pos.y), *this);
        
        if (i != pos.x)
            EmplaceMovement(moves, Pos(this->pos.x, i), *this);
        
        if (i != pos.x && i != pos.y) {
            EmplaceMovement(moves, Pos(i, i), *this);
            EmplaceMovement(moves, Pos(i, 7 - i), *this);
        }
    }
    return moves;
}

void King::draw() {
    std::cout << "K";
}

std::vector<Movement> King::GetMoves() {
    std::vector<Movement> moves;
    EmplaceMovement(moves, Pos(this->pos.x + 1, this->pos.y + 1), *this);
    EmplaceMovement(moves, Pos(this->pos.x + 1, this->pos.y - 1), *this);
    EmplaceMovement(moves, Pos(this->pos.x - 1, this->pos.y + 1), *this);
    EmplaceMovement(moves, Pos(this->pos.x - 1, this->pos.y - 1), *this);
    EmplaceMovement(moves, Pos(this->pos.x + 1, this->pos.y), *this);
    EmplaceMovement(moves, Pos(this->pos.x - 1, this->pos.y), *this);
    EmplaceMovement(moves, Pos(this->pos.x, this->pos.y + 1), *this);
    EmplaceMovement(moves, Pos(this->pos.x, this->pos.y - 1), *this);
    return moves;
}
