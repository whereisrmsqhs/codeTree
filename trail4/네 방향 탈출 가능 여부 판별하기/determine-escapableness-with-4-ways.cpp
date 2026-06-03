#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<vector<int>> grid;
vector<vector<bool>> visited;
int answer = 0;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

void BFS(int x, int y) {
    queue<pair<int, int>> q;
    visited[x][y] = true;
    q.push({ x,y });

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

            if (nx == N - 1 && ny == M - 1) {
                answer = 1;
                return;
            }

            visited[nx][ny] = true;
            q.push({ nx, ny });
        }
    }
}

int main() {
    cin >> N >> M;

    grid.resize(N, vector<int>(M));
    visited.resize(N, vector<bool>(M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
        }
    }

    if (grid[0][0] == 1) {
        BFS(0, 0);
    }

    cout << answer << "\n";
    return 0;
}