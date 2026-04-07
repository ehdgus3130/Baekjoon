#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

long long answer;
vector<char> oper;
vector<long long> num;

long long calc(long long a, long long b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    return a * b;
}

long long solution(string expression) {
    answer = 0;
    oper.clear();
    num.clear();

    vector<char> opers;
    string tmp;

    for (char s : expression) {
        if (!isdigit(s)) {
            oper.push_back(s);

            if (find(opers.begin(), opers.end(), s) == opers.end()) {
                opers.push_back(s);
            }

            num.push_back(stoll(tmp));
            tmp.clear();
        }
        else {
            tmp.push_back(s);
        }
    }
    num.push_back(stoll(tmp));

    sort(opers.begin(), opers.end());

    do {
        vector<long long> curNum = num;
        vector<char> curOper = oper;

        for (int k = 0; k < opers.size(); k++) {
            char target = opers[k];

            vector<long long> nextNum;
            vector<char> nextOper;

            nextNum.push_back(curNum[0]);

            for (int i = 0; i < curOper.size(); i++) {
                if (curOper[i] == target) {
                    long long a = nextNum.back();
                    nextNum.pop_back();
                    long long b = curNum[i + 1];
                    nextNum.push_back(calc(a, b, target));
                }
                else {
                    nextOper.push_back(curOper[i]);
                    nextNum.push_back(curNum[i + 1]);
                }
            }

            curNum = nextNum;
            curOper = nextOper;
        }

        answer = max(answer, llabs(curNum[0]));

    } while (next_permutation(opers.begin(), opers.end()));

    return answer;
}