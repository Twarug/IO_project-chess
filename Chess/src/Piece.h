#pragma once

#include "Color.h"
#include "Movement.h"
#include "Pos.h"

#include <vector>

class Piece {
protected:
    Pos pos;
    Color color;

public:
    Piece(Pos pos, Color color) : pos(pos), color(color) {};
    virtual ~Piece() = default;
    
    virtual void draw() = 0;

    virtual std::vector<Movement> GetMoves() = 0;

public:
    Pos GetPos() { return pos; }
    Color GetColor() { return color; }
};


class Pawn : public Piece {
public:
    Pawn(Pos pos, Color color) : Piece(pos, color) {}

    void draw() override;
    std::vector<Movement> GetMoves() override;
};

class Rook : public Piece {
public:
    Rook(Pos pos, Color color) : Piece(pos, color) {}

    void draw() override;
    std::vector<Movement> GetMoves() override;
};

class Knight : public Piece {
public:
    Knight(Pos pos, Color color) : Piece(pos, color) {}
    
    void draw() override;
    std::vector<Movement> GetMoves() override;
};

class Bishop : public Piece {
public:
    Bishop(Pos pos, Color color) : Piece(pos, color) {}
    
    void draw() override;
    std::vector<Movement> GetMoves() override;
};

class Queen : public Piece {
public:
    Queen(Pos pos, Color color) : Piece(pos, color) {}
    
    void draw() override;
    std::vector<Movement> GetMoves() override;
};

class King : public Piece {
public:
    King(Pos pos, Color color) : Piece(pos, color) {}
    
    void draw() override;
    std::vector<Movement> GetMoves() override;
};
