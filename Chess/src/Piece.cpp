#include "Piece.h"

#include <iostream>

class MovementsBuilder {
    std::vector<Movement> moves;

    Pos pos;
    Piece* piece;
public:
    MovementsBuilder& SetPos(Pos pos) { this->pos = pos; return *this; }
    MovementsBuilder& SetPos(int x, int y) { this->pos = {x, y}; return *this; }
    
    MovementsBuilder& SetPiece(Piece& piece) { this->piece = &piece; return *this; }

    MovementsBuilder& SubmitMovement() {
        if (piece != nullptr && pos.x >= 0 && pos.x <= 7 && pos.y >=0 && pos.y <=7)
            moves.emplace_back(pos, *piece);
        return *this;
    }

    std::vector<Movement> Build() { return moves; }
};


void Pawn::draw() {
    std::cout << "P";
}

std::vector<Movement> Pawn::GetMoves() {
    MovementsBuilder moves;
    moves.SetPiece(*this);
    if (this->color == Color::WHITE) {
        if (this->pos.y == 1)
            moves.SetPos(this->pos.x, this->pos.y + 2).SubmitMovement();
        moves.SetPos(this->pos.x, this->pos.y + 1).SubmitMovement();
    } else {
        if (this->pos.y == 6)
            moves.SetPos(this->pos.x, this->pos.y - 2).SubmitMovement();
        moves.SetPos(this->pos.x, this->pos.y - 1).SubmitMovement();
    }
    return moves.Build();
}

void Rook::draw() {
    std::cout << "R";
}

std::vector<Movement> Rook::GetMoves() {
    MovementsBuilder moves;
    moves.SetPiece(*this);
    for (int i = 0; i < 8; ++i) {
        if (i != pos.y)
            moves.SetPos(i, this->pos.y).SubmitMovement();
        
        if (i != pos.x)
            moves.SetPos(this->pos.x, i).SubmitMovement();
    }
    return moves.Build();
}

void Knight::draw() {
    std::cout << "N";
}

std::vector<Movement> Knight::GetMoves() {
    MovementsBuilder moves;
    moves.SetPiece(*this);
    moves.SetPos(this->pos.x + 2, this->pos.y + 1).SubmitMovement();
    moves.SetPos(this->pos.x + 2, this->pos.y - 1).SubmitMovement();
    moves.SetPos(this->pos.x - 2, this->pos.y + 1).SubmitMovement();
    moves.SetPos(this->pos.x - 2, this->pos.y - 1).SubmitMovement();
    moves.SetPos(this->pos.x + 1, this->pos.y + 2).SubmitMovement();
    moves.SetPos(this->pos.x + 1, this->pos.y - 2).SubmitMovement();
    moves.SetPos(this->pos.x - 1, this->pos.y + 2).SubmitMovement();
    moves.SetPos(this->pos.x - 1, this->pos.y - 2).SubmitMovement();
    return moves.Build();
}

void Bishop::draw() {
    std::cout << "B";
}

std::vector<Movement> Bishop::GetMoves() {
    MovementsBuilder moves;
    moves.SetPiece(*this);
    for (int i = 1; i < 8; ++i) {
        moves.SetPos(pos + Pos(i, i)).SubmitMovement();
        moves.SetPos(pos + Pos(i, -i)).SubmitMovement();
        moves.SetPos(pos + Pos(-i, i)).SubmitMovement();
        moves.SetPos(pos + Pos(-i, -i)).SubmitMovement();
    }
    return moves.Build();
}

void Queen::draw() {
    std::cout << "Q";
}

std::vector<Movement> Queen::GetMoves() {
    MovementsBuilder moves;
    moves.SetPiece(*this);
    for (int i = 0; i < 8; ++i) {
        if (i != pos.y)
            moves.SetPos(i, this->pos.y).SubmitMovement();
        
        if (i != pos.x)
            moves.SetPos(this->pos.x, i).SubmitMovement();
        
        if (i != pos.x && i != pos.y) {
            moves.SetPos(i, i).SubmitMovement();
            moves.SetPos(i, 7 - i).SubmitMovement();
        }
    }
    return moves.Build();
}

void King::draw() {
    std::cout << "K";
}

std::vector<Movement> King::GetMoves() {
    MovementsBuilder moves;
    moves.SetPiece(*this);
    
    moves.SetPos(this->pos.x + 1, this->pos.y + 1).SubmitMovement();
    moves.SetPos(this->pos.x + 1, this->pos.y - 1).SubmitMovement();
    moves.SetPos(this->pos.x - 1, this->pos.y + 1).SubmitMovement();
    moves.SetPos(this->pos.x - 1, this->pos.y - 1).SubmitMovement();
    moves.SetPos(this->pos.x + 1, this->pos.y).SubmitMovement();
    moves.SetPos(this->pos.x - 1, this->pos.y).SubmitMovement();
    moves.SetPos(this->pos.x, this->pos.y + 1).SubmitMovement();
    moves.SetPos(this->pos.x, this->pos.y - 1).SubmitMovement();
    return moves.Build();
}
