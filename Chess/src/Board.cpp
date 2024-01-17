#include "Board.h"

#include "Utils.h"

#include <iostream>
#include <algorithm>
#include <vector>

void Board::display() {
    std::vector<Movement> movements = selected ? selected->GetMoves() : std::vector<Movement>();

    // std::cout << movements.size() << '\n';

    int x = 0, y = 0;
    for (auto& row : reverse(board)) {
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
        std::cout << '\n';
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