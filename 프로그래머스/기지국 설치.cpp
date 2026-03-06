#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long long LL;

int solution(int n, vector<int> stations, int w)
{
    long long answer = 0;
    long long cover = 2LL * w + 1;

    long long pos = 1;

    for (int s : stations) {
        long long left = (long long)s - w;
        long long right = (long long)s + w;

        if (left > pos) {
            long long gap = left - pos;
            answer += (gap + cover - 1) / cover;
        }
        pos = max(pos, right + 1);
        if (pos > n) break;
    }
    if (pos <= n) {
        long long gap = (LL)n - pos + 1;
        answer += (gap + cover - 1) / cover;
    }

    return answer;
}