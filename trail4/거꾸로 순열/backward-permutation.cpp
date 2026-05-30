#include <iostream>
#include <vector>
using namespace std;

int N;
vector<bool> visited;
vector<int> answer;

void PrintAnswer() {
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }
    cout << "\n";
}

void Choose(int cur_idx) {
    if (cur_idx >= N + 1) {
        PrintAnswer();
        return;
    }

    for (int i = N; i > 0; i--) {
        if (visited[i]) continue;

        visited[i] = true;    
        answer.push_back(i);

        Choose(cur_idx + 1);
    
        visited[i] = false;
        answer.pop_back();
    }
}

int main() {
    cin >> N;
    visited.resize(N + 1);

    Choose(1);
}