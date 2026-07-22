#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int N;
pair<int, int> a[1001];
int dp[1001];

void Initialize() {

    for (int i = 0; i <= N; i++) {
        dp[i] = 1;
    }
}

int main() {
    cin >> N;

    int f, s;
    for (int i = 1; i <= N; i++) {
        cin >> f >> s;
        a[i] = { f, s };
    }

    sort(a + 1, a + N + 1);

    Initialize();

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            if (a[j].second < a[i].first) {
                dp[i] = max(dp[j] + 1, dp[i]);
            }
        }
    }

    int answer = 1;
    for (int i = 1; i <= N; i++) {
        if (dp[i] > answer) {
            answer = dp[i];
        }
    }

    cout << answer << "\n";

    return 0;
}