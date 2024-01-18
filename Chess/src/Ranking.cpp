#include "Ranking.h"

#include <fstream>
#include <iostream>
#include <string>

Ranking::Ranking(const std::string &filename) : sourceFile(filename) {
    scoreList = loadScoresFromFile(sourceFile);
}

void Ranking::addScore(const UserScore &score) {
    scoreList.push_back(score);
    saveScoresToFile(scoreList, sourceFile);
}

void Ranking::addScore(const std::string &nickanme, const float score){
    UserScore usc = UserScore(nickanme, score);
    scoreList.push_back(usc);
    saveScoresToFile(scoreList, sourceFile);
}

int Ranking::getScore(const std::string &nickname) {
    for (const auto &score : scoreList) {
        if (score.getNickname() == nickname) {
            return score.getScore();
        }
    }
    return -1;
}

void Ranking::printManager() {
    std::cout << "Ranking:\n";

    while (true) {
        std::string input;
        std::cout << "\n\n1) Wypisz \n";
        std::cout << "2) Znajdz \n";
        std::cout << "q) Wyjdz \n";
        std::cout << "!!!Dla testow!!!\n4) Dodaj \n";
        std::cout << "Wybierz: ";
        std::getline(std::cin, input);

        if (input == "1") {
            std::cout << "\nWyniki:\n";
            for (const auto &score : scoreList) {
                std::cout << score.getNickname() << ": " << score.getScore() << "\n";
            }
            std::cout << "==============\n";
        } else if (input == "2") {
            std::string nickname;
            std::cout << "\nPodaj nick: ";
            std::getline(std::cin, nickname);
            int score = getScore(nickname);
            if (score == -1) {
                std::cout << "\nNie znaleziono\n";
            } else {
                std::cout << score << "\n";
            }
        } else if (input == "q") {
            break;
        } else if (input == "4") {
            std::string nickname;
            int score = 0;
            std::cout << "\nPodaj nick: ";
            std::getline(std::cin, nickname);
            std::cout << "Podaj wynik: ";
            std::cin >> score;
            std::cin.ignore();
            addScore(UserScore(nickname, score));
            std::cout << "Pomyslnie dodano\n";
        } else {
            std::cout << "\nNiepoprawny wybor\n";
        }
    }
}

void Ranking::saveScoresToFile(const std::vector<UserScore> &scores, const std::string &filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const auto &score : scores) {
            file << score.getNickname() << " " << score.getScore() << std::endl;
        }
        file.close();
    }
}

std::vector<UserScore> Ranking::loadScoresFromFile(const std::string &filename) {
    std::vector<UserScore> scores;
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string name;
        int score;
        while (file >> name >> score) {
            UserScore *uScore = new UserScore();
            uScore->setNickname(name);
            uScore->setScore(score);
            scores.emplace_back(*uScore);
        }
        file.close();
    }
    return scores;
}