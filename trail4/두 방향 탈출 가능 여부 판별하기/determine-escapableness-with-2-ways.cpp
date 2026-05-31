#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<vector<int>> grid;
vector<vector<bool>> visited;
bool answer = false;

bool InRange(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < M;
}

bool CanGo(int x, int y) {
    if (!InRange(x, y)) {
        return false;
    }
    if (visited[x][y] || grid[x][y] == 0) {
        return false;
    }

    return true;
}

void DFS(int x, int y) {

    if (x == N - 1 && y == M - 1) {
        answer = 1;
        return;
    }

    int dx[2] = { 1, 0 };
    int dy[2] = { 0, 1 };

    for (int i = 0; i < 2; i++) {
        int new_x = x + dx[i];
        int new_y = y + dy[i];

        if (CanGo(new_x, new_y)) {
            visited[new_x][new_y] = true;
            DFS(new_x, new_y);
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

    DFS(0, 0);

    cout << answer << "\n";
    return 0;
}