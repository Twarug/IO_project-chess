#include "src/InputNotationManager.h";
#include "src/Ranking.h";
#include <iostream>

int main() {

    Ranking *ranking = new Ranking("ranking.txt");

    InputNotationManager *inputNotationManager = new InputNotationManager();
    // ranking->printManager();
    bool startGame = inputNotationManager->InputManager();

    if (startGame == true)
        std::cout << "Game starts" << std::endl;

    return 0;
}