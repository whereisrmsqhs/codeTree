#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> sequence;
int answer = 0;

void R(int count) {
    if (count >= N) {
        if (sequence.size() == N) answer += 1;
        return;
    }

    for (int i = 1; i <= 4; i++) {
        for (int j = 0; j < i; j++) {
            sequence.push_back(i);
        }
        R(count + i);
        for (int j = 0; j < i; j++) {
            sequence.pop_back();
        }
    }
}
    
int main() {
    // Please write your code here.
    cin >> N;

    R(0);
    cout << answer << "\n";
    return 0;
}