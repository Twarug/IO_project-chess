#include "Piece.h"

#include <iostream>

// void Pawn::draw() {
//     std::cout << "P";
// }

// std::vector<Movement> Pawn::GetMoves() {
//     std::vector<Movement> moves;
//     if (this->color == Color::WHITE) {
//         moves.emplace_back(Pos(this->pos.x, this->pos.y + 1), *this);
//     } else {
//         moves.emplace_back(Pos(this->pos.x, this->pos.y - 1), *this);
//     }
//     return moves;
// }

// void Rook::draw() {
//     std::cout << "R";
// }

// std::vector<Movement> Rook::GetMoves() {
//     std::vector<Movement> moves;
//     for (int i = 0; i < 8; ++i) {
//         if (i != pos.y)
//             moves.emplace_back(Pos(i, this->pos.y), *this);

//         if (i != pos.x)
//             moves.emplace_back(Pos(this->pos.x, i), *this);
//     }
//     return moves;
// }

// void Knight::draw() {
//     std::cout << "N";
// }

// std::vector<Movement> Knight::GetMoves() {
//     std::vector<Movement> moves;
//     moves.emplace_back(Pos(this->pos.x + 2, this->pos.y + 1), *this);
//     moves.emplace_back(Pos(this->pos.x + 2, this->pos.y - 1), *this);
//     moves.emplace_back(Pos(this->pos.x - 2, this->pos.y + 1), *this);
//     moves.emplace_back(Pos(this->pos.x - 2, this->pos.y - 1), *this);
//     moves.emplace_back(Pos(this->pos.x + 1, this->pos.y + 2), *this);
//     moves.emplace_back(Pos(this->pos.x + 1, this->pos.y - 2), *this);
//     moves.emplace_back(Pos(this->pos.x - 1, this->pos.y + 2), *this);
//     moves.emplace_back(Pos(this->pos.x - 1, this->pos.y - 2), *this);
//     return moves;
// }