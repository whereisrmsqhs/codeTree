#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> numList;
int answer = 1000000;
int sum = 0;
int combSum = 0;

void Combination(int index, int level) {
    if (level >= N) {
        int otherSum = sum - combSum;
        int difference = abs(combSum - otherSum);

        if (difference < answer) {
            answer = difference;
        }
        return;
    }

    for (int i = index; i < 2*N; i++) {
        combSum += numList[i];
        Combination(i + 1, level + 1);
        combSum -= numList[i];
    }
}

int main() {
    cin >> N;
    numList.resize(2*N);

    int input;
    for (int i = 0; i < 2*N; i++) {
        cin >> input;
        numList[i] = input;

        sum += input;
    }

    Combination(0, 0);
    cout << answer << "\n";

    return 0;
}