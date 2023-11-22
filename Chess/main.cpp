#include "src/Ranking.h";
#include <iostream>

int main() {

    Ranking *ranking = new Ranking("ranking.txt");

    ranking->printManager();
    return 0;
}