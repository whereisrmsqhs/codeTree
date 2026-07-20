#include <iostream>
#include <climits>
using namespace std;

int N, M;
int a[51][51];
int dp[51][51];

void Initialize() {
    dp[0][0] = 0;

    for (int i = 1; i < N; i++) {
        dp[i][0] = INT_MIN;
    }

    for (int j = 1; j < M; j++) {
        dp[0][j] = INT_MIN;
    }

    for (int i = 1; i < N; i++) {
        for (int j = 1; j < M; j++) {
            if (a[i][j] > a[0][0]) {
                dp[i][j] = dp[0][0] + 1;
            } 
            else {
                dp[i][j] = INT_MIN;
            }
        }
    }
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> a[i][j];
        }
    }

    Initialize();

    for (int i = 1; i < N; i++) {
        for (int j = 1; j < M; j++) {
            for (int k = i + 1; k < N; k++) {
                for (int l = j + 1; l < M; l++) {
                    if (a[k][l] > a[i][j]) {
                        dp[k][l] = max(dp[i][j] + 1, dp[k][l]);
                    }
                }
            }
        }
    }

    int answer = 0;
    for (int i = 1; i < N; i++) {
        for (int j = 1; j < M; j++) {
            if (dp[i][j] > answer) {
                answer = dp[i][j];
            }
        }
    }

    cout << answer + 1 << "\n";
    return 0;
}