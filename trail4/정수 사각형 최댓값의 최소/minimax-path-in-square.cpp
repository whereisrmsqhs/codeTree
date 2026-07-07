#include <iostream>
using namespace std;

int N;
int grid[101][101];
int dp[101][101];

void Initialize() {
    dp[0][0] = grid[0][0];

    for (int i = 1; i < N; i++) {
        dp[i][0] = max(dp[i - 1][0], grid[i][0]);
    }

    for (int j = 1; j < N; j++) {
        dp[0][j] = max(dp[0][j - 1], grid[0][j]);
    }
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    Initialize();

    for (int i = 1; i < N; i++) {
        for (int j = 1; j < N; j++) {
            dp[i][j] = max(min(dp[i - 1][j], dp[i][j - 1]), grid[i][j]);
        }
    }

    cout << dp[N - 1][N - 1] << "\n";

    return 0;
}