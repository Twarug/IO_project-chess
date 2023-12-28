#include "Board.h"
#include <iostream>
#include <vector>

class AI {
public:
  AI() {
    // moves not implemented yet when this was written
    srand(static_cast<unsigned int>(time(nullptr)));
  }

  std::string chooseMove(const std::vector<std::string> &moves,
                         const Board &board) {
    int bestMoveValue = -1;
    std::string bestMove = "";

    for (const std::string &move : moves) {
      int moveValue = evaluateMove(move, board);
      if (moveValue > bestMoveValue) {
        bestMoveValue = moveValue;
        bestMove = move;
      }
    }

    if (bestMove.empty() && !moves.empty()) {
      bestMove = moves[rand() % moves.size()];
    }

    return bestMove;
  }

private:
  int evaluateMove(const std::string &move, const Board &board) {
    // placeholder for evaluation function
    // cant be done until moves are implemented
    // for now return 0
    return 0;
  }
};