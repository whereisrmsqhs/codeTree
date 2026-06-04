#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, K;
vector<vector<int>> grid;
vector<vector<bool>> visited;
pair<int, int> curPos;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int maxNum = 0;

void ChooseNewPos() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == maxNum && visited[i][j]) {
                curPos = { i, j };
                return;
            }
        }
    }
}

void BFS(int x, int y) {
    queue<pair<int, int>> q;
    visited[x][y] = true;
    q.push({ x, y });

    while (!q.empty()) {
        pair<int, int> frontPos = q.front();
        q.pop();
        int cx = frontPos.first;
        int cy = frontPos.second;

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if (visited[nx][ny]) continue;
            if (grid[nx][ny] >= grid[x][y]) continue;

            if (grid[nx][ny] > maxNum) {
                maxNum = grid[nx][ny];
            }

            visited[nx][ny] = true;
            q.push({ nx, ny });
        }
    }
}

void InitVisited() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            visited[i][j] = false;
        }
    }
}

int main() {
    cin >> N >> K;

    grid.resize(N, vector<int>(N));
    visited.resize(N, vector<bool>(N));


    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    int x, y;
    cin >> x >> y;

    curPos = { x-1 , y-1 };

    int round = 0;
    while (round < K) {
        InitVisited();
        maxNum = 0;
        BFS(curPos.first, curPos.second);

        if (maxNum == 0) {
            break;
        }
        
        ChooseNewPos();
        round += 1;
    }

    cout << curPos.first + 1 << " " << curPos.second + 1 << "\n";
    return 0;
}