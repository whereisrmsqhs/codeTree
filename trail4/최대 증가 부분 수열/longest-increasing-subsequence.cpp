#include <iostream>
using namespace std;

int N;
int a[1001];
int dp[1001];

void Initialize() {
    for (int i = 0; i < N; i++) {
        dp[i] = 1;
    }
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    Initialize();

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int answer = 1;
    for (int i = 0; i < N; i++) {
        if (dp[i] > answer)
            answer = dp[i];
    }

    cout << answer << "\n";
    return 0;
}