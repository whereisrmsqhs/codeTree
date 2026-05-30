#include <iostream>
#include <vector>
using namespace std;

int N;
vector<vector<int>> grid;
vector<bool> visited;
vector<int> colOrder;
int answer = -1;

void SumChoosen() {
    int sum = 0;
    for (int i = 0; i < colOrder.size(); i++) {
        int colIdx = colOrder[i];

        sum += grid[i][colIdx];
    }

    if (sum > answer) {
        answer = sum;
    }
}

void Choose(int cur_idx) {
    if (cur_idx >= N ) {
        SumChoosen();
        return;
    }

    for (int i = 0; i < N; i++) {
        if (visited[i]) continue;

        visited[i] = true;
        colOrder.push_back(i);

        Choose(cur_idx + 1);

        visited[i] = false;
        colOrder.pop_back();
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