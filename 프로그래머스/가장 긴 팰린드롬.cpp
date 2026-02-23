#include <iostream>
#include <string>
using namespace std;
/*
    중심 확장
    전체 n 길이에서 한 칸식 이동하며 중간을 잡고 양쪽을 확인한다
*/
int expand(string& s, int l, int r) {
    int n = s.size();
    while (l >= 0 && r < n && s[l] == s[r]) { l--; r++; }
    return r - l - 1;
}
int solution(string s) {
    int n = (int)s.size();
    int answer = 1;

    for (int i = 0; i < n; ++i) {
        answer = max(answer, expand(s, i, i));       // 홀수
        if (i + 1 < n) answer = max(answer, expand(s, i, i + 1)); // 짝수
    }
    return answer;
}