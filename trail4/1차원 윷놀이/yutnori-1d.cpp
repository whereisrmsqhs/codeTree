#include <iostream>
#include <vector>
using namespace std;

int N, M, K;
vector<int> moveList;
vector<int> curPos;
int answer = 0;

void Permutation(int level) {
    if (level >= N) {
        int total = 0;
        for (int i = 0; i < curPos.size(); i++) {
            if (curPos[i] >= M) {
                total += 1;
            }
        }

        if (total > answer) {
            answer = total;
        }
        return;
    }

    for (int i = 0; i < K; i++) {
        if (curPos[i] >= M) continue;
        curPos[i] += moveList[level];
        Permutation(level + 1);
        curPos[i] -= moveList[level];
    }

    int total = 0;
    for (int i = 0; i < curPos.size(); i++) {
        if (curPos[i] >= M) {
            total += 1;
        }
    }

    if (total > answer) {
        answer = total;
    }
}

int main() {
    // Please write your code here.
    cin >> N >> M >> K;

    moveList.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> moveList[i];
    }

    curPos.resize(K);
    for (int i = 0; i < curPos.size(); i++) {
        curPos[i] = 1;
    }

    Permutation(0);
    cout << answer << "\n";

    return 0;
}