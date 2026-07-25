#include <iostream>
#include <climits>
using namespace std;

int N, M;
int coin[101];
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
        cin >> coin[i];
    }

    Initialize();

    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            if (i >= coin[j]) {

                if (dp[i - coin[j]] == INT_MAX) continue;

                dp[i] = min(dp[i], dp[i - coin[j]] + 1);
            }
        }
    }

    int ans = dp[M];

    if (ans == INT_MAX)
        ans = -1;

    cout << ans;

    return 0;
}