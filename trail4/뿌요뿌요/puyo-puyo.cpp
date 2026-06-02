#include <iostream>
#include <vector>
using namespace std;

int N;
vector<vector<int>> grid;
vector<vector<bool>> visited;

int bombBlocks = 0;
int maxBlockNum = 1;
int blockCnt = 0;

int dx[4] = { 0, 1, -1, 0 };
int dy[4] = { 1, 0, 0, -1 };

void DFS(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
        if (visited[nx][ny]) continue;
        if (grid[nx][ny] != grid[x][y]) continue;

        blockCnt += 1;
        visited[nx][ny] = true;
        DFS(nx, ny);
    }
}

int main() {
    cin >> N;
    grid.resize(N, vector<int>(N));
    visited.resize(N, vector<bool>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j]) {
                visited[i][j] = true;
                blockCnt = 1;
                DFS(i, j);

                if (blockCnt >= 4) {
                    bombBlocks += 1;
                }
                if (blockCnt > maxBlockNum)
                    maxBlockNum = blockCnt;
            }
        }
    }

    cout << bombBlocks << " " << maxBlockNum << "\n";
    return 0;
}