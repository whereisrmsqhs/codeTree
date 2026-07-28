#include <iostream>
using namespace std;

int N;
long long dp[100001];

int main() {
    cin >> N;

    dp[0] = 1;

    for (int i = 1; i <= N; i++) {
        if (i >= 1) {
            dp[i] = (dp[i] + dp[i - 1]) % 10007;
        }

        if (i >= 2) {
            dp[i] = (dp[i] + dp[i - 2]) % 10007;
        }

        if (i >= 5) {
            dp[i] = (dp[i] + dp[i - 5]) % 10007;
        }
    }

    cout << dp[N]<< '\n';

    return 0;
}