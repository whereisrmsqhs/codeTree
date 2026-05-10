#include <iostream>
#include <vector>
using namespace std;

int K, N;
vector<int> answer;

void PrintAnswer() {
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }
    cout << "\n";
}

void Combination(int range, int order) {
    if (order > N || range > K) {
        PrintAnswer();
        return;
    }

    for (int select = 1; select <= K; select++) {
        answer.push_back(select);
        Combination(range, order+1);
        answer.pop_back();
    }
}

int main() {
    // Please write your code here.
    cin >> K >> N;

    Combination(1, 1);
    return 0;
}