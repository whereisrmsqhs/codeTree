#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, K;
vector<vector<int>> grid;
pair<int, int> startPos;
pair<int, int> endPos;
vector<pair<int, int>> wallList;

int answer = -1;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

void BFS(vector<vector<int>>& tempGrid, vector<vector<int>>& step, vector<vector<bool>>& visited) {
    int sx = startPos.first;
    int sy = startPos.second;
    queue<pair<int, int>> q;
    q.push({ sx, sy });
    visited[sx][sy] = true;

    while (!q.empty()) {
        pair<int, int> pos = q.front();
        q.pop();
        int cx = pos.first;
        int cy = pos.second;

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if (visited[nx][ny]) continue;
            if (tempGrid[nx][ny] == 1) continue;

            visited[nx][ny] = true;
            step[nx][ny] = step[cx][cy] + 1;
            q.push({ nx, ny });
        }
    }
}

void StartPath() {
    vector<vector<int>> tempGrid(N, vector<int>(N));
    vector<vector<int>> step(N, vector<int>(N));
    vector<vector<bool>> visited(N, vector<bool>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            tempGrid[i][j] = grid[i][j];
        }
    }

    for (int i = 0; i < wallList.size(); i++) {
        pair<int, int> wallPos = wallList[i];
        int wx = wallPos.first;
        int wy = wallPos.second;

        tempGrid[wx][wy] = 0;
    }

    BFS(tempGrid, step, visited);

    int ex = endPos.first;
    int ey = endPos.second;

    if (step[ex][ey] > 0) {
        if (answer == -1 || step[ex][ey] < answer) {
            answer = step[ex][ey];
        }
    }
}

void Combination(int x, int y, int curLevel) {
    if (curLevel == K) {
        StartPath();
        return;
    }

    for (int i = y + 1; i < N; i++) {
        if (grid[x][i] == 1) {
            wallList.push_back({ x, i });
            Combination(x, i, curLevel + 1);
            wallList.pop_back();
        }
    }

    for (int i = x + 1; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == 1) {
                wallList.push_back({ i, j });
                Combination(i, j, curLevel + 1);
                wallList.pop_back();
            }
        }
    }
}

int main() {
    cin >> N >> K;

    grid.resize(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    int sx, sy, ex, ey;
    cin >> sx >> sy >> ex >> ey;
    startPos = { sx - 1, sy - 1 };
    endPos = { ex - 1, ey - 1 };

    if (sx == ex && sy == ey) {
        cout << 0 << "\n";
        return 0;
    }

    if (K > 0) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (grid[i][j] == 1) {
                    wallList.push_back({ i, j });
                    Combination(i, j, 1);
                    wallList.pop_back();
                }
            }
        }
    }
    else {
        StartPath();
    }

    cout << answer << "\n";
    return 0;
}