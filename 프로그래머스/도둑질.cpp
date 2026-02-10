#include <string>
#include <vector>

using namespace std;

/*
1 10 20 4 40

->
0 1 10 20 4
0 10 20 4 40
*/

int solution(vector<int> money) {
    int answer = 0;

    int n = money.size();

    vector<int> dp1;
    vector<int> dp2;
    dp1.push_back(0); dp2.push_back(0);

    for (int i = 0; i < n - 1; i++) { dp1.push_back(money[i]); }
    for (int i = 1; i < n; i++) { dp2.push_back(money[i]); }

    for (int i = 2; i < n; i++) {
        dp1[i] = max(dp1[i - 1], dp1[i - 2] + dp1[i]);
    }

    for (int i = 2; i < n; i++) {
        dp2[i] = max(dp2[i - 1], dp2[i - 2] + dp2[i]);
    }

    answer = dp1[n - 1] > dp2[n - 1] ? dp1[n - 1] : dp2[n - 1];
    return answer;
}