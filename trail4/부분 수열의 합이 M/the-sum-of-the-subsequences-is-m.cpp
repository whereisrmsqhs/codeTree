#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int N, M;
int A[101];
int dp[10001];

void Initialize() {
    dp[0] = 0;

    for (int i = 1; i <= M; i++) {
        dp[i] = INT_MAX;
    }
}

int main() {
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    sort(A + 1, A + N + 1);
    Initialize();

    for (int i = 1; i <= N; i++) {
        for (int j = M; j > 0; j--) {
            if (j >= A[i]) {
                if (dp[j - A[i]] == INT_MAX) continue;

                dp[j] = min(dp[j], dp[j - A[i]] + 1);
            }
        }
    }

    int ans = dp[M];

    if (ans == INT_MAX)
        ans = -1;

    cout << ans;

    return 0;
}