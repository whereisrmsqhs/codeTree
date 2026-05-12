#include <iostream>
#include <vector>
using namespace std;

int N;
vector<vector<int>> grid;
vector<pair<int, int>> bombsPos;
int answer = -1;

int dx0[4] = { -2, -1, 1, 2};
int dy0[4] = {0, 0, 0, 0};

int dx1[4] = {-1, 1, 0, 0};
int dy1[4] = {0, 0, -1, 1};

int dx2[4] = {-1, -1, 1, 1};
int dy2[4] = {-1, 1, -1, 1};

void Blowup(int bombIdx, int type) {
    int px = bombsPos[bombIdx].first;
    int py = bombsPos[bombIdx].second;

    if (type == 0) {
        for (int i = 0; i < 4; i++) {
            int nx = px + dx0[i];
            int ny = py + dy0[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N || grid[nx][ny] == 1) continue;
            if (grid[nx][ny] == 0) {
                grid[nx][ny] = 2;
            }
            else grid[nx][ny] += 1;
        }
    } 
    else if (type == 1) {
        for (int i = 0; i < 4; i++) {
            int nx = px + dx1[i];
            int ny = py + dy1[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N || grid[nx][ny] == 1) continue;
            if (grid[nx][ny] == 0) {
                grid[nx][ny] = 2;
            }
            else grid[nx][ny] += 1;
        }
    }
    else if (type == 2) {
        for (int i = 0; i < 4; i++) {
            int nx = px + dx2[i];
            int ny = py + dy2[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N || grid[nx][ny] == 1) continue;
            if (grid[nx][ny] == 0) {
                grid[nx][ny] = 2;
            }
            else grid[nx][ny] += 1;
        }
    }
}

void Undo(int bombIdx, int type) {
    int px = bombsPos[bombIdx].first;
    int py = bombsPos[bombIdx].second;

    if (type == 0) {
        for (int i = 0; i < 4; i++) {
            int nx = px + dx0[i];
            int ny = py + dy0[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N || grid[nx][ny] == 1 ) continue;
            grid[nx][ny] -= 1;
            if (grid[nx][ny] == 1) grid[nx][ny] = 0;
        }
    } 
    else if (type == 1) {
        for (int i = 0; i < 4; i++) {
            int nx = px + dx1[i];
            int ny = py + dy1[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N || grid[nx][ny] == 1) continue;
            grid[nx][ny] -= 1;
            if (grid[nx][ny] == 1) grid[nx][ny] = 0;

        }
    }
    else if (type == 2) {
        for (int i = 0; i < 4; i++) {
            int nx = px + dx2[i];
            int ny = py + dy2[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N || grid[nx][ny] == 1) continue;
            grid[nx][ny] -= 1;
            if (grid[nx][ny] == 1) grid[nx][ny] = 0;

        }
    }
}

void UpdateAnswer() {
    int total = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] > 0) total += 1;
        }
    }

    if (total > answer) answer = total;
}

void Backtracking(int index) {
    if (index >= bombsPos.size()) {
        // cout << "\n";
        // for (int i = 0; i < N; i++) {
        //     for (int j = 0; j < N; j++) {
        //         cout << grid[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        UpdateAnswer();
        return;
    }

    for (int i = 0; i < 3; i++) {
        Blowup(index, i);
        Backtracking(index + 1);
        Undo(index, i);

    }
}

int main() {
    // Please write your code here.
    cin >> N;
    
    grid.resize(N, vector<int>(N));
    
    int input;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> input;
            grid[i][j] = input;

            if (input == 1) bombsPos.push_back({i, j});
        }
    }

    Backtracking(0);
    cout << answer << "\n";

    return 0;
}