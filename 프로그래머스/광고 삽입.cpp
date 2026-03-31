#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> timeline;
/*
    누적 재생시간이 최대인 구간을 구하기
    1. logs에서 처음 시작구간과 마지막 구간에 대한
    누적합(prefix sum)
*/

int stringToInt(string str) {
    int PH = stoi(str.substr(0, 2));
    int PM = stoi(str.substr(3, 2));
    int PS = stoi(str.substr(6, 2));
    return (PH * 3600) + (PM * 60) + PS;
}

string logToString(int n) {
    string h1 = to_string(n / 3600);
    string m1 = to_string((n % 3600) / 60);
    string s1 = to_string(((n % 3600) % 60));
    if (h1.size() != 2) h1.insert(0, "0");
    if (m1.size() != 2) m1.insert(0, "0");
    if (s1.size() != 2) s1.insert(0, "0");

    return h1 + ":" + m1 + ":" + s1;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    if (play_time == adv_time) return "00:00:00";

    int pt_all = stringToInt(play_time);
    int adv_all = stringToInt(adv_time);

    timeline.resize(360000, 0);

    for (int i = 0; i < logs.size(); i++) {

        int start = stringToInt(logs[i].substr(0, 8));
        int end = stringToInt(logs[i].substr(9, 8));

        timeline[start] += 1;
        timeline[end] -= 1;
    }

    for (int i = 1; i <= pt_all; i++) timeline[i] += timeline[i - 1];
    for (int i = 1; i <= pt_all; i++) timeline[i] += timeline[i - 1];

    long long maxView = timeline[adv_all - 1];
    int answer = 0;

    for (int st = 1; st + adv_all - 1 <= pt_all; st++) {
        int end = st + adv_all - 1;
        long long cur = timeline[end] - timeline[st - 1];

        if (cur > maxView) {
            maxView = cur;
            answer = st;
        }
    }

    return logToString(answer);
}