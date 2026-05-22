#include <iostream>
#include <vector>
using namespace std;

int N;
vector<vector<int>> grid;
vector<vector<int>> gridDirection;
int dx[9] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[9] = { 0, 0, 1, 1, 1, 0, -1, -1, -1 };
pair<int, int> curPos;
int moveCount = 0;
int answer = 0;

void Move(int cx, int cy) {
    
    if (cx < 0 || cx >= N || cy < 0 || cy >= N) {
        if (moveCount > answer) {
            answer = moveCount;
        }
        return;
    }

    int tx = cx;
    int ty = cy;
    int dIdx = gridDirection[cx][cy];
    while (1) {
        tx += dx[dIdx];
        ty += dy[dIdx];

        if (tx < 0 || tx >= N || ty < 0 || ty >= N) break;

        if (grid[tx][ty] > grid[cx][cy]) {
            moveCount += 1;
            Move(tx, ty);
            moveCount -= 1;
        }
    }

    if (moveCount > answer) {
        answer = moveCount;
    }
}

int main() {
    cin >> N;

    grid.resize(N, vector<int>(N));
    gridDirection.resize(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> gridDirection[i][j];
        }
    }

    int r, c;
    cin >> r >> c;

    curPos = { r - 1, c - 1 };

    Move(r - 1, c - 1);
    
    cout << answer << "\n";
    return 0;
}