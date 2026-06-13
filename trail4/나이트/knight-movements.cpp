#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
vector<vector<int>> step;
vector<vector<bool>> visited;
queue<pair<int, int>> q;

int dx[8] = {-1, -2, -2, -1,  1,  2, 2, 1};
int dy[8] = {-2, -1,  1,  2, -2, -1, 1, 2};

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

        for (int i = 0; i < 8; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if (visited[nx][ny]) continue;

            Push(nx, ny, step[cx][cy] + 1);
        }
    }
}

int main() {
    cin >> N;

    step.resize(N, vector<int>(N));
    visited.resize(N, vector<bool>(N));

    int sx, sy, dx, dy;
    cin >> sx >> sy >> dx >> dy;

    if (sx == dx && sy == dy) {
        cout << 0 << "\n";
        return 0;
    }

    Push(sx - 1, sy - 1, 0);
    BFS();

    int destination = step[dx - 1][dy - 1];

    if (destination == 0) {
        cout << -1 << "\n";
    }
    else {
        cout << destination << "\n";
    }

    return 0;
}