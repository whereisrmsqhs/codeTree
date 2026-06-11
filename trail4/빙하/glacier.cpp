#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<vector<int>> grid;
vector<pair<int, int>> melt;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

void BFS() {
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(N, vector<bool> (M));

    visited[0][0] = true;
    q.push({ 0, 0 });

    while (!q.empty()) {
        pair<int, int> pos = q.front();
        int cx = pos.first;
        int cy = pos.second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (visited[nx][ny]) continue;
            if (grid[nx][ny] == 1) {
                visited[nx][ny] = true;
                melt.push_back({ nx, ny });
                continue;
            }

            visited[nx][ny] = true;
            q.push({ nx, ny });
        }
    }

}

int main() {
    cin >> N >> M;

    grid.resize(N, vector<int>(M));
    int last = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];

            if (grid[i][j] == 1) last += 1;
        }
    }

    int time = 0;
    while (1) {
        melt.clear();
        BFS();

        if (melt.empty()) break;

        last = melt.size();
        
        for (int i = 0; i < melt.size(); i++) {
            int mx = melt[i].first;
            int my = melt[i].second;

            grid[mx][my] = 0;
        }

        time++;
    }

    cout << time << " " << last << "\n";
    return 0;

}