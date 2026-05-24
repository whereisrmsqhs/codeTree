#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> jumpList;
int jumpCount = 0;
int answer = -1;

void Jump(int startIdx) {
    if (startIdx > N - 1) {
        return;
    }
    else if (startIdx == N - 1) {
        if (answer == -1) {
            answer = jumpCount;
        }
        else if (jumpCount < answer) {
            answer = jumpCount;
        }
        return;
    }

    for (int i = 1; i <= jumpList[startIdx]; i++) {
        jumpCount += 1;
        Jump(startIdx + i);
        jumpCount -= 1;

    }
}

int main() {
    cin >> N;
    jumpList.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> jumpList[i];
    }

    Jump(0);

    cout << answer << "\n";
    
    return 0;
}