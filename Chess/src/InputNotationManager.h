
#pragma once
#include "Notation.h"
#include "Board.h"
#include "Piece.h"
#include "Pos.h"
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
        default:
            return "Unknown";
        }
        return "Unknown";
    }

    std::string getColorName(Color color) {
        switch (color) {
        case Color::WHITE:
            return "White";
        case Color::BLACK:
            return "Black";
        default:
            return "Unknown";
        }
        return "Unknown";
    }

    void inputNotationAndType() {
        Notation notation;
        int type;
        int color;
        int x, y;
        char xChar;

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

        std::cout << "Enter x coordinate (A-H): ";
        std::cin >> xChar;
        std::cout << "Enter y coordinate (0-7): ";
        std::cin >> y;



        if ((xChar < 'A' || xChar > 'H') && (xChar < 'a' || xChar > 'h')) {
            std::cout << "Invalid x coordinate" << std::endl;
            return;
        } else {
            if(xChar >= 'a' && xChar <= 'h')
                x = xChar - 'a';
            else
                x = xChar - 'A';
        }

        std::cout << "xChar: " << xChar << std::endl << "x: " << x << std::endl;
        std::cout << "board[x][y]" << board[x][y] << std::endl;

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
            std::cout << "X Coordinate: " << (char)(notation.getX() + 'A') << std::endl;
            std::cout << "Y Coordinate: " << notation.getY() << std::endl;
            std::cout << std::endl;
        }
    }

    Board InputManager() {
        bool play = false;
        bool exit = false;

        while (true && notations.size() < TOTAL_PIECES) {
            std::string input;
            std::cout << "\n\n1) Wypisz \n";
            std::cout << "2) Dodaj \n";
            std::cout << "3) Graj \n";
            std::cout << "Wybierz: ";
            std::getline(std::cin, input);

            if (input == "1") {
                printCurrentNotations();
            } else if (input == "2") {
                inputNotationAndType();
            } else if (input == "3") {
                play = true;
                break;
            }
        }

        std::cout << "HALO" << std::endl;

        Board::BoardArray boardArray;

        if(play){
            for (const auto &notation : notations) {

                std::cout << "Piece Type: " << getPieceTypeName(notation.getPieceType()) << std::endl;
                std::cout << "Color: " << getColorName(notation.getColor()) << std::endl;
                std::cout << "X Coordinate: " << (char)(notation.getX() + 'A') << std::endl;
                std::cout << "Y Coordinate: " << notation.getY() << std::endl;
                std::cout << std::endl;

                switch(notation.getPieceType()){
                    case PieceType::KING:
                        boardArray[notation.getX()][notation.getY()] = new King(Pos(notation.getX(), notation.getY()), notation.getColor());
                        break;
                    case PieceType::QUEEN:
                        boardArray[notation.getX()][notation.getY()] = new Queen(Pos(notation.getX(), notation.getY()), notation.getColor());
                        break;
                    case PieceType::ROOK:
                        boardArray[notation.getX()][notation.getY()] = new Rook(Pos(notation.getX(), notation.getY()), notation.getColor());
                        break;
                    case PieceType::BISHOP:
                        boardArray[notation.getX()][notation.getY()] = new Bishop(Pos(notation.getX(), notation.getY()), notation.getColor());
                        break;
                    case PieceType::KNIGHT:
                        boardArray[notation.getX()][notation.getY()] = new Knight(Pos(notation.getX(), notation.getY()), notation.getColor());
                        break;
                    case PieceType::PAWN:
                        boardArray[notation.getX()][notation.getY()] = new Pawn(Pos(notation.getX(), notation.getY()), notation.getColor());
                        break;
                }
            }

            std::system("pause");
        }

        return Board(boardArray);
    }

private:
    std::vector<Notation> notations;
    int board[8][8] = {
        {-1, -1, -1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1, -1, -1},
    };

    int blackCounts[6] = {0};
    int whiteCounts[6] = {0};

    const int MAX_PIECE_COUNT[6] = {1, 1, 2, 2, 2, 8};
    const int TOTAL_PIECES = 32;
};