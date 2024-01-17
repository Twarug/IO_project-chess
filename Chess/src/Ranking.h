#pragma once

#include "UserScore.h"
#include <fstream>
#include <iostream>
#include <vector>

class Ranking {
public:
    Ranking(const std::string &filename);

    void addScore(const UserScore &score);
    int getScore(const std::string &nickname);
    void printManager();

private:
    std::string sourceFile;
    std::vector<UserScore> scoreList;

    std::vector<UserScore> loadScoresFromFile(const std::string &filename);
    void saveScoresToFile(const std::vector<UserScore> &scores, const std::string &filename);
};
