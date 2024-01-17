
#include <algorithm>
#include <string>

class UserScore {
public:
    UserScore() : nickname(""), score(0) {}
    UserScore(const std::string &nickname, float score) : nickname(nickname), score(score) {}

    void setNickname(const std::string &nickname) {
        this->nickname = nickname;
    }

    void setScore(float score) {
        this->score = score;
    }

    std::string getNickname() const {
        return nickname;
    }

    float getScore() const {
        return score;
    }

private:
    std::string nickname;
    float score;
};
