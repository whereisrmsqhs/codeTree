#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<vector<int>> grid;
vector<bool> visited;

void DFS(int vertex) {
    for (int cur_v = 1; cur_v <= N; cur_v++) {
        if (grid[vertex][cur_v] && !visited[cur_v]) {
            visited[cur_v] = true;
            DFS(cur_v);
        }
    }
}

int main() {
    cin >> N >> M;

    visited.resize(N + 1);
    grid.resize(N + 1, vector<int>(N + 1));

    int first, second;
    for (int i = 0; i < M; i++) {
        cin >> first >> second;

        grid[first][second] = 1;
        grid[second][first] = 1;
    }

    DFS(1);

    int answer = 0;
    for (int i = 0; i < visited.size(); i++) {
        if (visited[i]) {
            answer += 1;
        }
    }

    if (answer > 0) {
        answer -= 1;
    }
    cout << answer << "\n";

    return 0;
}