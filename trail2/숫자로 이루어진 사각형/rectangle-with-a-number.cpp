#include <iostream>
using namespace std;

int main() {
    // Please write your code here.
    int N;
    cin >> N;

    int num = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            num += 1;
            if (num == 10) num = 1;
            cout << num << " ";
        }
        cout << "\n";
    }
    return 0;
}