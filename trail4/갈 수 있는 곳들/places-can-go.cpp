#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, K;
vector<vector<int>> grid;
vector<vector<bool>> visited;
vector<pair<int, int>> startPoints;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1, -1, 0, 0 };

void BFS(int x, int y) {
    queue<pair<int, int>> q;
    visited[x][y] = true;
    q.push({ x, y });

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
            if (grid[nx][ny] == 1) continue;

            visited[nx][ny] = true;
            q.push({ nx, ny });
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
    for (int i = 0; i < K; i++) {
        cin >> x >> y;
        startPoints.push_back({ x-1, y-1 });
    }

    for (int i = 0; i < startPoints.size(); i++) {
        int sx = startPoints[i].first;
        int sy = startPoints[i].second;

        BFS(sx, sy);
    }

    int answer = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (visited[i][j]) {
                answer += 1;
            }
        }
    }

    cout << answer << "\n";
    return 0;
} 