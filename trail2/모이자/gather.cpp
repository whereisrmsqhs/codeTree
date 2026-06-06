#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

int main() {
    // Please write your code here.
    int N;
    cin >> N;

    vector<int> people(N);
    for (int i = 0; i < N; i++) {
        cin >> people[i];
    }

    int answer = INT_MAX;
    for (int i = 0; i < N; i++) {
        int moveSum = 0;
        for (int j = 0; j < N; j++) {
            if (j == i) continue;
            int peopleNum = people[j];
            int distance = abs(i-j);

            moveSum += (peopleNum * distance);
        }

        if (moveSum < answer) answer = moveSum;
    }

    cout << answer << "\n";
    return 0;
}