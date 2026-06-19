#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
bool visited[1000001];
int answer = 0;

void BFS() {
    queue<pair<int, int>> q;
    q.push({N, 0});
    visited[N] = true;

    while (!q.empty()) {
        pair<int, int> root = q.front();
        q.pop();
        int rootNum = root.first;
        int rootLevel = root.second;

        if (rootNum == 1) {
            answer = rootLevel;
            break;
        }
    
        for (int i = 0; i < 4; i++) {
            int nextNum;
            int nextLevel = rootLevel + 1;
            if (i == 0) {
                if (visited[rootNum - 1]) continue;
                nextNum = rootNum - 1;
            } 
            else if (i == 1) {
                if (visited[rootNum + 1]) continue;
                nextNum = rootNum + 1;
            } 
            else if (i == 2) {
                if (rootNum % 2 != 0) continue;
                if (visited[rootNum / 2]) continue;
                nextNum = rootNum / 2;
            }
            else if (i == 3) {
                if (rootNum % 3 != 0) continue;
                if (visited[rootNum / 3]) continue;
                nextNum = rootNum / 3;
            }
            visited[nextNum] = true;
            q.push({ nextNum, nextLevel });
        }
    }
}

int main() {
    cin >> N;

    BFS();

    cout << answer << "\n";
    return 0;
}