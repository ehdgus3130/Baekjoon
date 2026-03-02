#include <iostream>
#include <vector>
using namespace std;
/*
    1,2,3,5
    5,6,7,8
    4,3,2,1

0,1/ 1,2/ 2,3/ 3,5

*/
int solution(vector<vector<int>> land)
{
    int answer = 0;
    int n = land.size();

    int a = land[0][0];
    int b = land[0][1];
    int c = land[0][2];
    int d = land[0][3];

    for (int i = 1; i < n; i++) {
        int na = land[i][0] + max(b, max(c, d));
        int nb = land[i][1] + max(a, max(c, d));
        int nc = land[i][2] + max(a, max(b, d));
        int nd = land[i][3] + max(a, max(b, c));
        a = na, b = nb, c = nc, d = nd;
    }

    return max(a, max(b, max(c, d)));
}
