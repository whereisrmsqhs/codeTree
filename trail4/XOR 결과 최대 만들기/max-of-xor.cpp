#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> inputList;
vector<int> tempList;
int answer = -1;

void Combination(int idx, int level) {
    if (level >= M) {
        int total = 0;
        for (int i = 0; i < tempList.size(); i++) {
            total = total ^ tempList[i];
        }

        if (total > answer) {
            answer = total;
        }
        return;
    }

    for (int i = idx; i < N; i++) {
        tempList.push_back(inputList[i]);
        Combination(i + 1, level + 1);
        tempList.pop_back();
    }
    
}

int main() {
    cin >> N >> M;

    inputList.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> inputList[i];
    }

    Combination(0, 0);
    cout << answer << "\n";

    return 0;
}