#include <iostream>
#include <climits>
using namespace std;

int N;
int a[1001];
int dp[1001];

void Initialize() {
    dp[0] = 0;

    for (int i = 1; i < N; i++) {
        dp[i] = INT_MIN;
    }
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    Initialize();

    for (int i = 1; i < N; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (j + a[j] >= i) {
                dp[i] = max(dp[j] + 1, dp[i]);
            }
        }
    }

    int answer = 1;
    for (int i = 0; i < N; i++) {
        if (dp[i] > answer) {
            answer = dp[i];
        }
    }

    cout << answer << "\n";

    return 0;
}