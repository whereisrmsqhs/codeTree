#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
using namespace std;

string formula;
vector<int> valList(6);
int answer = -99999999;

void CalculateFormula() {
    int curIdx = 0;
    stack<int> s;
    while (curIdx < formula.size()) {
        int charNum = formula[curIdx];

        if (charNum >= 97 && charNum <= 102) {
            int idx = charNum - 97;
            if (s.empty()) {
                s.push(valList[idx]);
            }
            else {
                int symbol = s.top();
                s.pop();
                int firstVal = s.top();
                s.pop();

                // symbol 숫자로 +, -, *, /
                int result;
                if (symbol == 43) {
                    result = firstVal + valList[idx];
                }
                else if (symbol == 45) {
                    result = firstVal - valList[idx];
                }
                else if (symbol == 42) {
                    result = firstVal * valList[idx];
                }
                else if (symbol == 47) {
                    result = firstVal / valList[idx];
                }

                // 계산하고 현재 idx가 마지막이면 걍 이게 식 마지막 결과고 아니면 다시 stack에 넣음.
                if (curIdx + 1 >= formula.size()) {
                    if (result > answer) answer = result;
                }
                else {
                    s.push(result);
                }
            }
        }
        else {
            s.push(charNum);
        }
        curIdx += 1;
    }

    // 문자 하나인 경우
    if (!s.empty()) {
        int singleVal = s.top();
        s.pop();

        if (singleVal > answer) {
            answer = singleVal;
        }
    }
}

void Permutation(int idx) {
    if (idx >= 6) {
        CalculateFormula();
        return;
    }

    for (int i = 1; i <= 4; i++) {
        valList[idx] = i;
        Permutation(idx + 1);
    }
}

int main() {
    cin >> formula;

    Permutation(0);

    cout << answer << "\n";
    return 0;
}