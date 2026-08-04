#include <iostream>
#include <climits>
using namespace std;

int N, M;
int dp[10001];
int w[101];
int v[101];

void Initialize() {
    dp[0] = 0;

    for (int i = 1; i <= M; i++) {
        dp[i] = INT_MIN;
    }
}

int main() {
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cin >> w[i] >> v[i];
    }

    Initialize();

    for (int i = 1; i <= N; i++) {
        for (int j = M; j >= w[i]; j--) {
            if (w[i] <= j) {

                if (dp[j - w[i]] == INT_MIN) continue;

                dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
            }
        }
    }

    int answer = dp[0];
    for (int i = 1; i <= M; i++) {
        if (dp[i] > answer)
            answer = dp[i];
    }

    cout << answer << "\n";
    return 0;
}