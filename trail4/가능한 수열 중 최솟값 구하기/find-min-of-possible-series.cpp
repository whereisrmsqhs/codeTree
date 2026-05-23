#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
using namespace std;

int N;
vector<int> list;

bool isDuplicate(int newIdx, int newVal) {

    vector<int> temp = list;
    temp[newIdx] = newVal;

    int len = newIdx + 1;

    for (int range = 1; range <= len / 2; range++) {

        bool same = true;

        for (int i = 0; i < range; i++) {

            int left = temp[len - range * 2 + i];
            int right = temp[len - range + i];

            if (left != right) {
                same = false;
                break;
            }
        }

        if (same) {
            return true;
        }
    }

    return false;
}

void Combination(int idx, int level) {

    if (level >= N) {
        for (int i = 0; i < list.size(); i++) {
            cout << list[i];
        }
        cout << "\n";

        exit(0);
    }

    for (int i = 4; i <= 6; i++) {

        if (isDuplicate(idx, i))
            continue;

        list[idx] = i;

        Combination(idx + 1, level + 1);
    }
}

int main() {

    cin >> N;

    list.resize(N);

    Combination(0, 0);
}