#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> answer;
vector<bool> visited;

void PrintAnswer() {
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }
    cout << endl;
}

void Choose(int curr_num) {
    if (curr_num == N + 1) {
        PrintAnswer();
        return;
    }

    for (int i = 1; i <= N; i++) {
        if (visited[i]) {
            continue;
        }

        visited[i] = true;
        answer.push_back(i);

        Choose(curr_num + 1);

        answer.pop_back();
        visited[i] = false;
    }
}

int main() {
    cin >> N;

    visited.resize(N + 1);
    Choose(1);
    return 0;
}