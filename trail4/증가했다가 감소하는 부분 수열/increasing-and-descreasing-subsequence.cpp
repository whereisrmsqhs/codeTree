#include <iostream>
#include <algorithm>
using namespace std;

int N;
int a[1001];
int dp[1001][2];

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < N; i++) {
        dp[i][0] = 1;  // 증가 상태
        dp[i][1] = 1;  // 감소 상태
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i]) {
                // 증가 중인 수열만 계속 증가할 수 있음
                dp[i][0] = max(dp[i][0], dp[j][0] + 1);
            }
            else if (a[j] > a[i]) {
                // 증가 상태에서 감소를 시작하거나,
                // 감소 상태에서 계속 감소
                dp[i][1] = max(
                    dp[i][1],
                    max(dp[j][0], dp[j][1]) + 1
                );
            }
        }
    }

    int answer = 1;

    for (int i = 0; i < N; i++) {
        answer = max(answer, dp[i][0]);
        answer = max(answer, dp[i][1]);
    }

    cout << answer << '\n';

    return 0;
}