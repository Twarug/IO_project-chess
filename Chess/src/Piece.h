#include "Color.h"
#include "Pos.h"
#include "Movement.h"

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
};


class Pawn : public Piece {
public:
    void draw() override;
    std::vector<Movement> GetMoves() override;
};

class Rook : public Piece {
public:
    void draw() override;
    std::vector<Movement> GetMoves() override;
};


class Knight : public Piece {
public:
    void draw() override;
    std::vector<Movement> GetMoves() override;
};

class Bishop : public Piece {
public:
    void draw() override;
    std::vector<Movement> GetMoves() override;
};

class Queen : public Piece {
public:
    void draw() override;
    std::vector<Movement> GetMoves() override;
};

class King : public Piece {
public:
    void draw() override;
    std::vector<Movement> GetMoves() override;
};