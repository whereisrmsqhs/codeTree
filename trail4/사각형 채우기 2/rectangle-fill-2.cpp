#include <iostream>
using namespace std;

const int MOD = 10007;

int main() {
    int N;
    cin >> N;

    int dp[1001] = {};

    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 3;

    for (int i = 3; i <= N; i++) {
        dp[i] = (dp[i - 2] * 2 + dp[i - 1]) % MOD;
    }

    cout << dp[N] << '\n';
    return 0;
}