#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int N, M;
vector<pair<int, int>> ladderList;
vector<int> answerList;

void FindAnswer() {
    vector<vector<int>> grid(16, vector<int>(N+1));

    for (int i = 0; i < ladderList.size(); i++) {
        pair<int, int> connection = ladderList[i];

        int start = connection.first;
        int end = connection.first + 1;
        int row = connection.second;

        grid[row][start] = end;
        grid[row][end] = start;
    }

    //for (int i = 1; i < 16; i++) {
    //    for (int j = 1; j <= N; j++) {
    //        cout << grid[i][j] << " ";
    //    }
    //    cout << "\n";
    //}

    for (int i = 1; i <= N; i++) {
        pair<int, int> curPos = { 1, i };
        int time = 1;

        //cout << i << "사다리 타기 시작!" << "\n";
        while (time < 16) {
            int x = curPos.first;
            int y = curPos.second;
            //cout << x << ", " << y << "\n";
            if (grid[x][y] != 0) {
                int newCol = grid[x][y];
                curPos = { x + 1, newCol };
            }
            else {
                curPos = { x + 1, y };
            }
            time += 1;
        }

        answerList.push_back(curPos.second);
    }

    //cout << "\n";
    //for (int i = 0; i < answerList.size(); i++) {
    //    cout << answerList[i] << " ";
    //}
    //cout << "\n";

}

vector<int> PlayLadder(vector<vector<int>>& grid, int maxLevel) {
    vector<int> results;

    for (int i = 1; i <= N; i++) {
        pair<int, int> curPos = { 1, i };
        int time = 1;

        while (time < 16) {
            int x = curPos.first;
            int y = curPos.second;
            if (grid[x][y] != 0) {
                int newCol = grid[x][y];
                curPos = { x + 1, newCol };
            }
            else {
                curPos = { x + 1, y };
            }
            time += 1;
        }

        results.push_back(curPos.second);
    }

    return results;
}

void SetLadder(pair<int, int>& ladder, vector<vector<int>>& grid) {
    int start = ladder.first;
    int end = ladder.first + 1;
    int row = ladder.second;

    grid[row][start] = end;
    grid[row][end] = start;
}

void UnsetLadder(pair<int, int>& ladder, vector<vector<int>>& grid) {
    int start = ladder.first;
    int end = ladder.first + 1;
    int row = ladder.second;

    grid[row][start] = 0;
    grid[row][end] = 0;
}

void Combination(int idx, int level, int maxLevel, vector<vector<int>>& grid) {
    if (level >= maxLevel) {
        // 사다리 배치 완료, 결과 확인후 정답 업데이트
        // 사다리 타기, 결과 나오면 answer과 비교

        vector<int> LadderResult = PlayLadder(grid, maxLevel);
        bool allMatch = true;
        for (int i = 0; i < LadderResult.size(); i++) {
            if (LadderResult[i] != answerList[i]) {
                allMatch = false;
                break;
            }
        }
        if (allMatch) {
            cout << maxLevel << "\n";
            exit(0);
        }
        return;
    }

    for (int i = idx; i < M; i++) {
        SetLadder(ladderList[i], grid);
        Combination(i + 1, level + 1, maxLevel, grid);
        UnsetLadder(ladderList[i], grid);
    }
}

void InitGrid(vector<vector<int>>& grid) {
    for (int i = 1; i < 16; i++) {
        for (int j = 1; j <= N; j++) {
            grid[i][j] = 0;
        }
    }
}

int main() {
    // Please write your code here.
    cin >> N >> M;

    int first, second;
    for (int i = 0; i < M; i++) {
        cin >> first >> second;
        ladderList.push_back({ first, second });
    }

    FindAnswer();

    vector<vector<int>> grid(16, vector<int>(N+1));
    for (int i = 0; i <= M; i++) {
        InitGrid(grid);
        Combination(0, 0, i, grid);
    }

    return 0;
}