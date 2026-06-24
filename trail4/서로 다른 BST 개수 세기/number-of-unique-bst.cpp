#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    long long dp[20] = {};
    dp[0] = 1;

    for (int i = 1; i <= N; i++) {
        for (int left = 0; left < i; left++) {
            int right = i - 1 - left;
            dp[i] += dp[left] * dp[right];
        }
    }

    cout << dp[N] << "\n";
}