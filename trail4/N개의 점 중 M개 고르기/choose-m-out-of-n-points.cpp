#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N, M;
vector<pair<int, int>> coord;
vector<pair<int, int>> choosen;
vector<pair<int, int>> temp;

int answer = 100000;
int maxResult = -1;

void ChoosenCombination(int index, int level) {
    if (level >= 2) {

        pair<int, int> fc = temp[0];
        pair<int, int> sc = temp[1];

        int result = pow(fc.first - sc.first, 2) + pow(fc.second - sc.second, 2);
        if (result > maxResult) {
            maxResult = result;
        }

        return;
    }

    for (int i = index; i < choosen.size(); i++) {
        temp.push_back(choosen[i]);
        ChoosenCombination(i + 1, level + 1);
        temp.pop_back();
    }
}

void Combination(int index, int level) {
    if (level >= M) {
        
        ChoosenCombination(0, 0);

        if (maxResult < answer) {
            answer = maxResult;
        }

        maxResult = -1;

        return;
    }

    for (int i = index; i < N; i++) {
        choosen.push_back(coord[i]);
        Combination(i + 1, level + 1);
        choosen.pop_back();
    }
}

int main() {
    cin >> N >> M;

    int first, second;
    for (int i = 0; i < N; i++) {
        cin >> first >> second;

        coord.push_back({ first, second });
    }

    Combination(0, 0);

    cout << answer << "\n";
    return 0;
}