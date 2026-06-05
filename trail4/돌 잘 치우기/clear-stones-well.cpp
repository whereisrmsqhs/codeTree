#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int N, K, M;
vector<vector<int>> grid;
vector<vector<bool>> visited;
vector<pair<int, int>> startPoints;
stack<pair<int, int>> s;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int answer = 0;

void BFS(int x, int y, int& totalArea) {
    totalArea += 1;
    queue<pair<int, int>> q;
    visited[x][y] = true;
    q.push({ x, y });

    while (!q.empty()) {
        pair<int, int> coord = q.front();
        int cx = coord.first;
        int cy = coord.second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if (visited[nx][ny]) continue;
            if (grid[nx][ny] == 1) continue;

            visited[nx][ny] = true;
            q.push({ nx, ny });
            totalArea += 1;
        }
    }
}

void Search() {
    int totalArea = 0;
    for (int i = 0; i < startPoints.size(); i++) {
        pair<int, int> coord = startPoints[i];
        int x = coord.first;
        int y = coord.second;

        if (!visited[x][y]) {
            BFS(x, y, totalArea);
        }
    }

    if (totalArea > answer) {
        answer = totalArea;
    }
}

void InitVisited() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            visited[i][j] = false;
        }
    }
}

void RemoveStone(int sx, int sy, int curLevel) {
    if (curLevel >= K) {
        Search();
        InitVisited();
        return;
    }

    for (int i = sx; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == 1) {
                s.push({ i, j });
                grid[i][j] = 0;
                RemoveStone(i, j + 1, curLevel + 1);

                pair<int, int> c = s.top();
                s.pop();
                grid[c.first][c.second] = 1;
            }
        }
    }
}

int main() {
    cin >> N >> M >> K;
    grid.resize(N, vector<int>(N));
    visited.resize(N, vector<bool>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    int x, y;
    for (int i = 0; i < M; i++) {
        cin >> x >> y;
        startPoints.push_back({ x - 1, y - 1 });
    }


    RemoveStone(0, 0, 0);

    cout << answer << "\n";
    return 0;
}