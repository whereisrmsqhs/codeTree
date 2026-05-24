#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> temp;

void Combination(int idx, int level) {
    if (level > M) {
        for (int i = 0; i < temp.size(); i++) {
            cout << temp[i] << " ";
        }
        cout << "\n";

        return;
    }

    for (int i = idx; i <= N; i++) {
        temp.push_back(i);
        Combination(i + 1, level + 1);
        temp.pop_back();
    }
}

int main() {
    cin >> N >> M;

    Combination(1, 1);
}