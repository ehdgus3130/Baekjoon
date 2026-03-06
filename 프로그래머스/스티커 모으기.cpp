#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int solve(const vector<int>& sticker, int l, int r) {
    int prev2 = 0;
    int prev1 = 0;
    for (int i = l; i <= r; i++) {
        int cur = max(prev1, prev2 + sticker[i]);
        prev2 = prev1;
        prev1 = cur;
    }
    return prev1;
}

int solution(vector<int> sticker)
{
    int answer = 0;
    int n = sticker.size();
    if (n == 1) return sticker[0];
    if (n == 2) return (max(sticker[0], sticker[1]));

    return max(solve(sticker, 0, n - 2), solve(sticker, 1, n - 1));

}