#include <string>
#include <vector>

using namespace std;
vector<vector<int>> ans;

/*
원판 n개를 from → to로 옮기고 싶고, 보조 기둥이 aux라면:
위의 n-1개를 from → aux로 옮긴다. (to를 보조로 사용)
가장 큰 원판 n을 from → to로 옮긴다.
aux에 있던 n-1개를 aux → to로 옮긴다. (from을 보조로 사용)
    1 3 / 1 2 / 3 1 / 2 3 / 1 3 / 1 2 / 3 2 / 3 1 / 2 1 / 2 3 / 1 2 / 1 3 / 2 3
*/
void hanoi(int n, int from, int aux, int to) {
    if (n == 0) return;
    hanoi(n - 1, from, to, aux);
    ans.push_back({ from, to });
    hanoi(n - 1, aux, from, to);
}

vector<vector<int>> solution(int n) {
    ans.clear();
    hanoi(n, 1, 2, 3);
    return ans;
}