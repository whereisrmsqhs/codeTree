#include <iostream>
#include <vector>
using namespace std;

int main() {
    long dp[1001] = {};
    dp[2] = 1;
    dp[3] = 1;
    int N;
    cin >> N;

    for (int i = 4; i <= N; i++) {
        dp[i] = (dp[i - 2] + dp[i - 3]) % 10007;
    }

    cout << dp[N] << "\n";
    return 0;
}