#include <iostream>
using namespace std;

const long long MOD = 1000000007;

int main() {
    int N;
    cin >> N;

    long long dp[1001] = {};

    dp[0] = 1;
    dp[1] = 2;
    dp[2] = 7;

    for (int i = 3; i <= N; i++) {
        dp[i] = (3 * dp[i - 1] + dp[i - 2] - dp[i - 3]) % MOD;
        if (dp[i] < 0) dp[i] += MOD;
    }

    cout << dp[N] << '\n';
    return 0;
}