#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<vector<int>> grid;
vector<vector<int>> dp;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int DFS(int x, int y) {
    if (dp[x][y] != 0) return dp[x][y];

    dp[x][y] = 1;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
        if (grid[nx][ny] <= grid[x][y]) continue;

        dp[x][y] = max(dp[x][y], DFS(nx, ny) + 1);
    }

    return dp[x][y];
}

int main() {
    cin >> N;

    grid.resize(N, vector<int>(N));
    dp.resize(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    int answer = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            answer = max(answer, DFS(i, j));
        }
    }

    cout << answer << '\n';

    return 0;
}