
#pragma once
#include "Notation.h"
#include <iostream>
#include <vector>

class InputNotationManager {
public:
    void printPieceTypes() {
        std::cout << "Piece Types:" << std::endl;
        for (int i = static_cast<int>(PieceType::KING); i <= static_cast<int>(PieceType::PAWN); ++i) {
            PieceType piece = static_cast<PieceType>(i);
            std::cout << i << ": " << getPieceTypeName(piece) << std::endl;
        }
    }

    std::string getPieceTypeName(PieceType piece) {
        switch (piece) {
        case PieceType::KING:
            return "King";
        case PieceType::QUEEN:
            return "Queen";
        case PieceType::ROOK:
            return "Rook";
        case PieceType::BISHOP:
            return "Bishop";
        case PieceType::KNIGHT:
            return "Knight";
        case PieceType::PAWN:
            return "Pawn";
        }
    }

    std::string getColorName(Color color) {
        switch (color) {
        case Color::WHITE:
            return "White";
        case Color::BLACK:
            return "Black";
        }
    }

    void inputNotationAndType() {
        Notation notation;
        int type;
        int color;
        int x, y;

        printPieceTypes();
        std::cout << "Enter piece type (0-" << static_cast<int>(PieceType::PAWN) << "): ";
        std::cin >> type;

        std::cout << "Enter color (0 - White, 1 - Black): ";
        std::cin >> color;

        if (color == 0) {
            if (whiteCounts[type] >= MAX_PIECE_COUNT[type]) {
                std::cout << "You can't add more pieces of this type" << std::endl;
                return;
            }
            whiteCounts[type]++;
        } else {
            if (blackCounts[type] >= MAX_PIECE_COUNT[type]) {
                std::cout << "You can't add more pieces of this type" << std::endl;
                return;
            }
            blackCounts[type]++;
        }

        std::cout << "Enter x coordinate (0-7): ";
        std::cin >> x;
        std::cout << "Enter y coordinate (0-7): ";
        std::cin >> y;

        if (board[x][y] != -1) {
            std::cout << "There is already a piece on this field" << std::endl;
            return;
        }

        notation.setPieceType(static_cast<PieceType>(type));
        notation.setColor(static_cast<Color>(color));
        notation.setX(x);
        notation.setY(y);

        notations.push_back(notation);
        board[x][y] = static_cast<int>(notation.getPieceType());
    }

    void printCurrentNotations() {
        std::cout << "Current Board Look:" << std::endl;
        for (const auto &notation : notations) {
            std::cout << "Piece Type: " << getPieceTypeName(notation.getPieceType()) << std::endl;
            std::cout << "Color: " << getColorName(notation.getColor()) << std::endl;
            std::cout << "X Coordinate: " << notation.getX() << std::endl;
            std::cout << "Y Coordinate: " << notation.getY() << std::endl;
            std::cout << std::endl;
        }
    }

    bool InputManager() {
        bool play = false;

        while (true && notations.size() < TOTAL_PIECES) {
            std::string input;
            std::cout << "\n\n1) Wypisz \n";
            std::cout << "2) Dodaj \n";
            std::cout << "3) Graj \n";
            std::cout << "4) Wyjdz \n";
            std::cout << "Wybierz: ";
            std::getline(std::cin, input);

            if (input == "1") {
                printCurrentNotations();
            } else if (input == "2") {
                inputNotationAndType();
            } else if (input == "3") {
                play = true;
                break;
            } else if (input == "4") {
                break;
            }
        }

        return play;
    }

private:
    std::vector<Notation> notations;
    int board[8][8] = {-1};

    int blackCounts[6] = {0};
    int whiteCounts[6] = {0};

    const int MAX_PIECE_COUNT[6] = {1, 1, 2, 2, 2, 8};
    const int TOTAL_PIECES = 32;
};