#include <string>
#include <vector>

using namespace std;
/*
    수에 대해서 이진탐색
    전체를 탐색해서 최대값을 구한다 최소값(1이상이니 1로 고정)
    그럼 이제 중앙값을 기준으로 했을때 k안에 못지나가는게 있는지 확인
*/

bool canCross(const vector<int>& stones, int mid, int k) {
    int cnt = 0;
    for (int i = 0; i < stones.size(); i++) {
        if (stones[i] - mid < 0) cnt++;
        else cnt = 0;

        if (cnt >= k) return false;
    }
    return true;
}

int solution(vector<int> stones, int k) {
    int answer = 0;

    long long low = 1, high = 0;
    for (long long v : stones) high = max(v, high);

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (canCross(stones, mid, k)) {
            answer = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return answer;
}