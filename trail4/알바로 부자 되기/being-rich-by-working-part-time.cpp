#include <iostream>
#include <climits>
using namespace std;

int N;
int s[1001];
int e[1001];
int p[1001];
int dp[1001];

void Initialize() {
    dp[1] = p[1];

    for (int i = 2; i <= N; i++) {
        dp[i] = p[i];
    }
}

int main() {
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> s[i] >> e[i] >> p[i];
    }

    Initialize();

    for (int i = 2; i <= N; i++) {
        for (int j = 1; j < i; j++) {
            if (e[j] < s[i]) {
                dp[i] = max(dp[i], dp[j] + p[i]);
            }
        }
    }

    int answer = dp[1];
    for (int i = 1; i <= N; i++) {
        answer = max(answer, dp[i]);
    }

    cout << answer << "\n";

    return 0;
}
