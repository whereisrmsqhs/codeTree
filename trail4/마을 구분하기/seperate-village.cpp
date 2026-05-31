#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<vector<int>> grid;
vector<vector<bool>> visited;
int villageNum = 0;
vector<int> villagePeople;
int peopleCnt = 0;

void DFS(int x, int y) {
    
    int dx[4] = { 0, 1, 0, -1 };
    int dy[4] = { 1, 0, -1, 0 };

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= N || ny < 0 || ny >= N || visited[nx][ny]) continue;
        if (grid[nx][ny] == 0) continue;

        peopleCnt += 1;
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
            if (!visited[i][j] && grid[i][j] == 1) {
                peopleCnt = 1;
                villageNum += 1;
                visited[i][j] = true;
                DFS(i, j);
                villagePeople.push_back(peopleCnt);
            }
        }
    }

    sort(villagePeople.begin(), villagePeople.end());

    cout << villageNum << "\n";
    for (int i = 0; i < villagePeople.size(); i++) {
        cout << villagePeople[i] << "\n";
    }

    return 0;
}