#include <iostream>
#include <vector>
using namespace std;

int N;
vector<vector<int>> grid;

int main() {
    cin >> N;

    grid.resize(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    int answer = 0;
    for (int i = 0; i <= N - 3; i++) {
        for (int j = 0; j <= N - 3; j++) {
            int cnt = 0;
            for (int k = i; k < i + 3; k++) {
                for (int n = j; n < j + 3; n++) {
                    if (grid[k][n] == 1) {
                        cnt += 1;
                    }
                }
            }
            if (cnt > answer) answer = cnt;
        }
    }

    cout << answer << "\n";
    return 0;
}