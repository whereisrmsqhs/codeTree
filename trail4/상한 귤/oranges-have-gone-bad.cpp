#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, K;
vector<vector<int>> grid;
vector<vector<int>> answer;
vector<vector<bool>> visited;
vector<pair<int, int>> decayed;
queue<pair<int, int>> q;

int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { -1, 0, 1, 0 };

void BFS() {
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
            if (grid[nx][ny] == 0 || grid[nx][ny] == 2) continue;
        
            answer[nx][ny] = answer[cx][cy] + 1;
            visited[nx][ny] = true;
            q.push({ nx, ny });
        }
    }
}

int main() {
    cin >> N >> K;

    grid.resize(N, vector<int>(N));
    answer.resize(N, vector<int>(N));
    visited.resize(N, vector<bool>(N));

    int val;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> val;

            if (val == 0) answer[i][j] = -1;
            else if (val == 2) {
                answer[i][j] = 0;
                decayed.push_back({ i, j });
            }
            grid[i][j] = val;
        }
    }

    for (int i = 0; i < decayed.size(); i++) {
        q.push(decayed[i]);
        int x = decayed[i].first;
        int y = decayed[i].second;

        visited[x][y] = true;
    }
    
    BFS();

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (answer[i][j] == 0 && visited[i][j] == false) {
                answer[i][j] = -2;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << answer[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}