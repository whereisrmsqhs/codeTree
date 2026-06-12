#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, K, U, D;
vector<vector<int>> grid;
vector<pair<int, int>> cityList;
vector<vector<bool>> visited;
int answer = 0;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

void BFS(int x, int y) {
    queue<pair<int, int>> q;
    visited[x][y] = true;
    q.push({ x, y });

    while (!q.empty()) {
        pair<int, int> cityPos = q.front();
        int cx = cityPos.first;
        int cy = cityPos.second;
        int cval = grid[cx][cy];
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if (visited[nx][ny]) continue;

            int nval = grid[nx][ny];
            int difference = abs(cval - nval);
            if (difference < U || difference > D) continue;

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

void Combination(int x, int y, int level) {
    if (level == K) {
        InitVisited();
        for (int i = 0; i < cityList.size(); i++) {
            pair<int, int> city = cityList[i];
            int cx = city.first;
            int cy = city.second;

            BFS(cx, cy);
        }

        int total = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (visited[i][j]) {
                    total += 1;
                }
            }
        }

        if (total > answer) answer = total;

        return;
    }

    for (int i = y; i < N; i++) {
        cityList.push_back({ x, i });
        Combination(x, i + 1, level + 1);
        cityList.pop_back();
    }

    for (int i = x + 1; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cityList.push_back({ i, j });
            Combination(i, j + 1, level + 1);
            cityList.pop_back();
        }
    }
}

int main() {
    cin >> N >> K >> U >> D;

    grid.resize(N, vector<int>(N));
    visited.resize(N, vector<bool>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    Combination(0, 0, 0);

    cout << answer << "\n";
    return 0;
}