#include <iostream>
#include <vector>
using namespace std;

int K, N;
vector<int> numList;

void Permutation(int level) {
    if (level >= N) {
        for (int i = 0; i < numList.size(); i++) {
            cout << numList[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 1; i <= K; i++) {
        if (level > 1 && numList[level - 1] == i && numList[level-2] == i) continue;
        numList.push_back(i);
        Permutation(level + 1);
        numList.pop_back();
    }
}

int main() {
    // Please write your code here.
    cin >> K >> N;

    numList.reserve(N);
    Permutation(0);

    return 0;
}