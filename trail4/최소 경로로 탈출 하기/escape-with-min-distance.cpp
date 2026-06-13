#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<vector<int>> grid;
vector<vector<int>> step;
vector<vector<bool>> visited;
queue<pair<int, int>> q;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void Push(int x, int y, int s) {
    step[x][y] = s;
    visited[x][y] = true;
    q.push({ x, y });
}

void BFS() {
    while (!q.empty()) {
        pair<int, int> pos = q.front();
        q.pop();
        int cx = pos.first;
        int cy = pos.second;

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (visited[nx][ny]) continue;
            if (grid[nx][ny] == 0) continue;

            Push(nx, ny, step[cx][cy] + 1);
        }
    }
}

int main() {
    cin >> N >> M;

    grid.resize(N, vector<int>(M));
    step.resize(N, vector<int>(M));
    visited.resize(N, vector<bool>(M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
        }
    }

    Push(0, 0, 0);
    BFS();

    int result = step[N - 1][M - 1];

    if (result == 0) {
        cout << -1 << "\n";
    }
    else {
        cout << step[N - 1][M - 1] << "\n";
    }

    return 0;
}