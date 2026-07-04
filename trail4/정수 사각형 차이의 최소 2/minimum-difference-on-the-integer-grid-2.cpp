#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N;
vector<vector<int>> grid;

int dx[2] = {1, 0};
int dy[2] = {0, 1};

bool CanGo(int low, int high) {
    if (grid[0][0] < low || grid[0][0] > high) return false;

    vector<vector<bool>> visited(N, vector<bool>(N, false));
    queue<pair<int, int>> q;

    q.push({0, 0});
    visited[0][0] = true;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        if (x == N - 1 && y == N - 1) return true;

        for (int dir = 0; dir < 2; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx >= N || ny >= N) continue;
            if (visited[nx][ny]) continue;
            if (grid[nx][ny] < low || grid[nx][ny] > high) continue;

            visited[nx][ny] = true;
            q.push({nx, ny});
        }
    }

    return false;
}

int main() {
    cin >> N;

    grid.resize(N, vector<int>(N));

    int minVal = 1e9;
    int maxVal = -1e9;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
            minVal = min(minVal, grid[i][j]);
            maxVal = max(maxVal, grid[i][j]);
        }
    }

    int answer = 1e9;

    for (int low = minVal; low <= maxVal; low++) {
        for (int high = low; high <= maxVal; high++) {
            if (high - low >= answer) continue;

            if (CanGo(low, high)) {
                answer = high - low;
                break;
            }
        }
    }

    cout << answer << '\n';

    return 0;
}