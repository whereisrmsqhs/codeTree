#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int N, H, M;
vector<vector<int>> grid;
vector<vector<int>> step;
vector<vector<bool>> visited;
vector<vector<int>> answer;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { -1, 1, 0, 0 };

void BFS(int x, int y) {
    queue<pair<int, int>> q;
    visited[x][y] = true;
    q.push({ x, y });
    step[x][y] = 0;

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

            step[nx][ny] = step[cx][cy] + 1;
            visited[nx][ny] = true;

            if (grid[nx][ny] == 3) break;
            q.push({ nx, ny });
        }
    }
}

void AssignPath(int x, int y) {
    int minTime = INT_MAX;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == x && j == y) continue;

            if (grid[i][j] == 3 && step[i][j] != 0) {
                if (step[i][j] < minTime) {
                    minTime = step[i][j];
                }
            }
        }
    }

    if (minTime == INT_MAX) {
        answer[x][y] = -1;
    }
    else {
        answer[x][y] = minTime;
    }
}

void InitVector() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            visited[i][j] = false;
            step[i][j] = 0;
        }
    }
}

int main() {
    cin >> N >> H >> M;

    grid.resize(N, vector<int>(N));
    step.resize(N, vector<int>(N));
    visited.resize(N, vector<bool>(N));
    answer.resize(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == 2) {
                BFS(i, j);

                AssignPath(i, j);
                InitVector();
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << answer[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}