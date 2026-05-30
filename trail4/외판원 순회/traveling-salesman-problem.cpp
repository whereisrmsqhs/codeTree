#include <iostream>
#include <vector>
using namespace std;

int N;
vector<bool> visited;
vector<int> colList;
vector<vector<int>> grid;
int answer = 100000;

void CalCost() {
    int sum = 0;
    int rowIdx = 0;
    for (int i = 0; i < colList.size(); i++) {
        int colIdx = colList[i];
        if (grid[rowIdx][colIdx] == 0) return;

        sum += grid[rowIdx][colIdx];
        rowIdx = colIdx;
    }

    if (grid[rowIdx][0] == 0) return;
    sum += grid[rowIdx][0];

    if (sum < answer) {
        answer = sum;
    }

    //cout << "sum : " << sum << "\n";
}

void Choose(int cur_idx) {
    if (cur_idx >= N - 1) {
        //for (int i = 0; i < colList.size(); i++) {
        //    cout << colList[i] << " ";
        //}
        //cout << "\n";
        CalCost();
        return;
    }

    for (int i = 1; i < N; i++) {
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

    grid.resize(N, vector<int>(N));
    visited.resize(N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    Choose(0);

    cout << answer << "\n";
    return 0;
}