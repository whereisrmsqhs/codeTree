#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int coin[101];
int dp[10001];

void Initialize() {
    dp[0] = 0;

    for (int i = 1; i <= M; i++) {
        dp[i] = -1;
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
                // 이전 금액을 만들 수 없는 경우
                if (dp[i - coin[j]] == -1) {
                    continue;
                }

                dp[i] = max(
                    dp[i],
                    dp[i - coin[j]] + 1
                );
            }
        }
    }

    cout << dp[M] << '\n';

    return 0;
}