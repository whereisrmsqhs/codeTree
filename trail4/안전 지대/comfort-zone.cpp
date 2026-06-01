#include <iostream>
#include <vector>
using namespace std;

int N, M;
int K = 0;
vector<vector<int>> grid;
vector<vector<int>> unsafeGrid;
vector<vector<bool>> visited;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void DFS(int x, int y) {
    
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
        if (unsafeGrid[nx][ny] == 1) continue;
        if (visited[nx][ny]) continue;

        visited[nx][ny] = true;
        DFS(nx, ny);
    }
}

bool isAllUnsafe() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (unsafeGrid[i][j] == 0) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    cin >> N >> M;

    grid.resize(N, vector<int>(M));
    visited.resize(N, vector<bool>(M));
    unsafeGrid.resize(N, vector<int>(M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
        }
    }

    int maxK = 1;
    int maxArea = 0;
    while (1) {
        K += 1;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (grid[i][j] == K) {
                    unsafeGrid[i][j] = 1;
                }
            }
        }

        if (isAllUnsafe()) {
            break;
        }

        int safeArea = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (!visited[i][j] && unsafeGrid[i][j] == 0) {
                    safeArea += 1;
                    visited[i][j] = true;
                    DFS(i, j);
                }
            }
        }

        if (safeArea > maxArea) {
            maxK = K;
            maxArea = safeArea;
        }

        vector<vector<bool>> emptyVisited(N, vector<bool>(M));
        visited = emptyVisited;
    }

    cout << maxK << " " << maxArea << "\n";

    return 0;
}