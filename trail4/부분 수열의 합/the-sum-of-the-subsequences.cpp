#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int N, M;
int a[101];
int dp[10001];

void Initialize() {
    dp[0] = 0;

    for (int i = 1; i <= M; i++) {
        dp[i] = INT_MIN;
    }
}

int main() {
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }

    Initialize();

    for (int i = 1; i <= N; i++) {
        for (int j = M; j >= i; j--) {
            if (a[i] <= j) {

                if (dp[j - a[i]] == INT_MIN) continue;

                dp[j] = max(dp[j - a[i]] + 1, dp[j]);
            }
        }
    }

    if (dp[M] != INT_MIN) {
        cout << "Yes\n";
    }
    else {
        cout << "No\n";
    }

    return 0;
}