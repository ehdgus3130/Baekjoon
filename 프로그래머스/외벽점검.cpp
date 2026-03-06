#include <string>
#include <vector>
#include <algorithm>
using namespace std;
/*
    각 weak사이 거리 확인 / dist 우선순위별로
    처리방법
    1. w위치에서 다른 w까지 d 가 닿이는지 확인
    2. 각 자리별로 진행해 최대 몇개까지 가능한지 확인
*/


int solution(int n, vector<int> weak, vector<int> dist) { //1 index
    int answer = 10;
    int size_W = weak.size();
    int size_D = dist.size();

    sort(dist.begin(), dist.end());

    vector<int> weak2(2 * size_W);
    for (int i = 0; i < size_W; ++i) {
        weak2[i] = weak[i];
        weak2[i + size_W] = weak[i] + n;
    }

    do {
        for (int s = 0; s < size_W; s++) {
            int idx = s;
            int used = 0;

            while (used < size_D && idx < s + size_W) {
                int limit = weak2[idx] + dist[used++];

                while (idx < s + size_W && weak2[idx] <= limit) idx++;
            }
            if (idx >= s + size_W) answer = min(answer, used);
        }

    } while (next_permutation(dist.begin(), dist.end()));

    return (answer == 10 ? -1 : answer);
}