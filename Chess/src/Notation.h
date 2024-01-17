#pragma once
#include "Color.h"
#include <string>

enum class PieceType : int {
    KING = 0,
    QUEEN,
    ROOK,
    BISHOP,
    KNIGHT,
    PAWN
};

class Notation {
public:
    Notation() = default;
    Notation(int _x, int _y, PieceType pieceType, Color _color)
        : x(_x), y(_y), pieceType(pieceType), color(_color) {}

    int getX() const {
        return x;
    }

    void setX(int _x) {
        x = _x;
    }

    int getY() const {
        return y;
    }

    void setY(int _y) {
        y = _y;
    }

    PieceType getPieceType() const {
        return pieceType;
    }

    void setPieceType(PieceType _pieceType) {
        pieceType = _pieceType;
    }

    void setColor(Color _color) {
        color = _color;
    }

    Color getColor() const {
        return color;
    }

private:
    int x;
    int y;
    Color color;
    PieceType pieceType;
};
