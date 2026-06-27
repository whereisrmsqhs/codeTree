#include <iostream>
#define MAX_N 101
using namespace std;

int N;
int a[MAX_N][MAX_N];
int dp[MAX_N][MAX_N];

void Initialize() {
    dp[0][N - 1] = a[0][N - 1];

    for (int j = N - 2; j >= 0; j--) {
        dp[0][j] = dp[0][j + 1] + a[0][j];
    }

    for (int i = 1; i < N; i++) {
        dp[i][N - 1] = dp[i - 1][N - 1] + a[i][N - 1];
    }
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> a[i][j];
        }
    }

    Initialize();

    for (int i = 1; i < N; i++) {
        for (int j = N - 2; j >= 0; j--) {
            dp[i][j] = min(dp[i - 1][j], dp[i][j + 1]) + a[i][j];
        }
    }

    cout << dp[N - 1][0] << "\n";
    return 0;
}