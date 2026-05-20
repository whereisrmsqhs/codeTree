#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N, M, C;
vector<vector<int>> grid;
int answer = 0;
vector<int> tempList;

void Combination(int idx, int level, int maxLevel, int& maxVal, vector<int> thiefList) {
    if (level >= maxLevel) {
        int total = 0;
        int totalWeight = 0;
        for (int i = 0; i < tempList.size(); i++) {
            if (tempList[i] + total > C) continue;
            else {
                total += tempList[i];
                totalWeight += pow(tempList[i], 2);
            }
        }

        if (totalWeight > maxVal) {
            maxVal = totalWeight;
        }

        return;
    }

    for (int i = idx; i < thiefList.size(); i++) {
        tempList.push_back(thiefList[i]);
        Combination(i + 1, level + 1, maxLevel, maxVal, thiefList);
        tempList.pop_back();
    }
}

void CheckResult(int fx, int fy, int sx, int sy) {
    vector<int> firstThief;
    vector<int> secondThief;

    for (int i = fy; i < fy + M; i++) {
        firstThief.push_back(grid[fx][i]);
    }

    for (int i = sy; i < sy + M; i++) {
        secondThief.push_back(grid[sx][i]);
    }

    int maxFirstWeight = 0;
    for (int i = 1; i <= firstThief.size(); i++) {
        Combination(0, 0, i, maxFirstWeight, firstThief);
    }

    int maxSecondWeight = 0;
    for (int i = 1; i <= secondThief.size(); i++) {
        Combination(0, 0, i, maxSecondWeight, secondThief);
    }

    if (maxFirstWeight + maxSecondWeight > answer) {
        answer = maxFirstWeight + maxSecondWeight;
    }
}

void SelectSecond(int fx, int fy) {

    for (int i = fy + M; i <= N - M; i++) {
        CheckResult(fx, fy, fx, i);
    }

    for (int i = fx + 1; i < N; i++) {
        for (int j = 0; j <= N - M; j++) {
            CheckResult(fx, fy, i, j);
        }
    }
}

int main() {
    cin >> N >> M >> C;

    grid.resize(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= N - M; j++) {
            SelectSecond(i, j);
        }
    }

    cout << answer << "\n";

    return 0;
}