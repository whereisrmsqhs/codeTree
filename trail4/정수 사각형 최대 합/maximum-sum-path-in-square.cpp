#include <iostream>
#define MAX_N 101
using namespace std;

int N;
int dp[MAX_N][MAX_N];
int a[MAX_N][MAX_N];

void Initialize() {
    dp[0][0] = a[0][0];

    for (int i = 1; i < N; i++) {
        dp[i][0] = dp[i - 1][0] + a[i][0];
    }

    for (int i = 1; i < N; i++) {
        dp[0][i] = dp[0][i - 1] + a[0][i];
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
        for (int j = 1; j < N; j++) {
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]) + a[i][j];
        }
    }

    cout << dp[N - 1][N - 1] << "\n";
    return 0;
    
}