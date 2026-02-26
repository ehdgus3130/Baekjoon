#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;
/*
    fees 기본시간/ 기본 요금/ 단위 시간/ 단위요금
*/
static map<int, vector<int>> m; //carNum, // cnt, lastTime, sum
int norTime, norMoney, defTime, defMoney;

void check(string s) {
    int carNum = stoi(s.substr(6, 4));
    int _hour = stoi(s.substr(0, 2));
    int _min = stoi(s.substr(3, 2));

    int lastTime = (_hour * 60) + _min;

    if (m.count(carNum) == 0) {
        vector<int> arr = { 1, lastTime, 0 };
        m.insert({ carNum, arr });
    }
    else {
        if (auto it = m.find(carNum); it != m.end()) {
            if (it->second[0] % 2 == 1)
                it->second[2] += (lastTime - it->second[1]);
            it->second[0] += 1;
            it->second[1] = lastTime;
        }
    }
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    int n = records.size();
    norTime = fees[0], norMoney = fees[1];
    defTime = fees[2], defMoney = fees[3];

    int deadLine = (23 * 60) + 59;

    for (string s : records) check(s);

    for (auto it = m.begin(); it != m.end(); it++) {
        int tmp = 0;
        if (it->second[0] % 2 == 1) {
            it->second[2] += (deadLine - it->second[1]);
        }
        double tmp1 = (it->second[2] - norTime);
        double tmp2 = defTime;

        tmp = norMoney + ceil(tmp1 / tmp2) * defMoney;
        if (it->second[2] < norTime) answer.push_back(norMoney);
        else answer.push_back(tmp);
    }

    return answer;
}