#include <iostream>
#include <vector>
using namespace std;

int N;
vector<bool> visited;
vector<int> colList;
vector<vector<int>> grid;
int answer = -1;

void FindMin() {
    int minVal = 100000;
    for (int i = 0; i < colList.size(); i++) {
        int colIdx = colList[i];

        if (grid[i][colIdx] < minVal) {
            minVal = grid[i][colIdx];
        }
    }

    if (minVal > answer) {
        answer = minVal;
    }
}

void Choose(int cur_idx) {
    if (cur_idx >= N ) {

        FindMin();
        return;
    }

    for (int i = 0; i < N; i++) {
        if (visited[i]) continue;

        visited[i] = true;
        colList.push_back(i);

        Choose(cur_idx + 1);

        visited[i] = false;
        colList.pop_back();
    }
}

int main() {
    cin >> N;

    visited.resize(N);
    grid.resize(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    Choose(0);
    cout << answer << "\n";
    return 0;
}