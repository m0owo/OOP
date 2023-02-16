#include "header.hpp"

float highest(vector<string> scores) {
    float highest = stof(scores[0]);
    for (string score: scores) {
        if (stof(score) > highest) {
            highest = stof(score);
        }
    }
    return highest;
}

float lowest(vector<string> scores) {
    float lowest = stof(scores[0]);
    for (string score: scores) {
        if (stof(score) < lowest) {
            lowest = stof(score);
        }
    }
    return lowest;
}

float average(vector<string> scores) {
    float sum = 0;
    for (string score: scores) {
        sum += stof(score);
    }
    return sum/scores.size();
}
