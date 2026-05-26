#include <iostream>
#include <cstring>
#include <vector>
#include <cctype>
#include <algorithm>
using namespace std;

class NumInfo {
public:
    int number;
    pair<int, int> pos;

    NumInfo(int n, pair<int, int> p)
        : number(n), pos(p) {
    }

    bool operator<(const NumInfo& other) const {
        return number < other.number;
    }
};

int N;
pair<int, int> startPoint;
pair<int, int> endPoint;
vector<vector<char>> grid;
vector<NumInfo> numInfoList;
vector<NumInfo> tempList;
int answer = 1000000;

void Move() {
    int moveCnt = 0;
    pair<int, int> curPos = startPoint;

    for (int i = 0; i < tempList.size(); i++) {
        NumInfo curNumInfo = tempList[i];

        moveCnt += (abs(curNumInfo.pos.first - curPos.first) + abs(curNumInfo.pos.second - curPos.second));
        curPos = curNumInfo.pos;
    }

    moveCnt += (abs(curPos.first - endPoint.first) + abs(curPos.second - endPoint.second));

    if (moveCnt < answer) {
        answer = moveCnt;
    }
}

void Combination(int idx, int level) {
    if (level >= 3) {
        Move();
        return;
    }

    for (int i = idx; i < numInfoList.size(); i++) {
        tempList.push_back(numInfoList[i]);
        Combination(i + 1, level + 1);
        tempList.pop_back();
    }
}

int main() {
    cin >> N;

    grid.resize(N, vector<char>(N));

    char input;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> input;

            if (isdigit(input)) {
                numInfoList.push_back(NumInfo(input - '0', { i, j }));
            }
            if (input == 'S') {
                startPoint = { i, j };
            }
            if (input == 'E') {
                endPoint = { i, j };
            }
            grid[i][j] = input;
        }
    }

    if (numInfoList.size() < 3) {
        cout << -1 << "\n";
        return 0;
    }

    sort(numInfoList.begin(), numInfoList.end());

    Combination(0, 0);

    cout << answer << "\n";
    return 0;

};