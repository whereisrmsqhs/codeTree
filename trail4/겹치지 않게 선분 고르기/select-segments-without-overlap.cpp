#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> line(1000);
vector<pair<int, int>> lineList;
vector<pair<int, int>> candidate;
int answer = 1;

void UpdateAnswer() {
    bool duplicate = false;
    for (int i = 0; i < candidate.size(); i++) {
        if (duplicate) break;
        pair<int, int> lineRange = candidate[i];

        int start = lineRange.first;
        int end = lineRange.second;

        for (int j = start; j <= end; j++) {
            if (line[j] == 0) line[j] += 1;
            else {
                duplicate = true;
                break;
            }
        }
    }

    if (!duplicate && candidate.size() > answer) {
        answer = candidate.size();
    }

    vector<int> emptyLine(1000);
    line = emptyLine;
}

void Combination(int index, int level, int maxLevel) {
    if (level == maxLevel) {
        UpdateAnswer();
        return;
    }

    for (int i = index; i < N; i++) {
        candidate.push_back(lineList[i]);
        Combination(i + 1, level + 1, maxLevel);
        candidate.pop_back();
    }
}

int main() {
    // Please write your code here.
    cin >> N;

    int x, y;
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        lineList.push_back({ x, y });
    }

    for (int i = 1; i <= N; i++) {
        Combination(0, 0, i);
    }

    cout << answer << "\n";

    return 0;
}