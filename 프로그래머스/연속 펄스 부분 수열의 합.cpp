#include <string>
#include <vector>

using namespace std;
const int INF = 1e9;

long long solution(vector<int> sequence) {

    int n = sequence.size();
    long long MX = -INF, cur = 0;
    long long MX_ = -INF, cur_ = 0;

    for (int i = 0; i < n; i++) {

        long long tmp = sequence[i];
        if (i % 2 == 0) tmp *= -1;

        cur = max(tmp, tmp + cur);
        MX = max(MX, cur);

        long long tmp_ = sequence[i];
        if (i % 2 == 1) tmp_ *= -1;

        cur_ = max(tmp_, tmp_ + cur_);
        MX_ = max(MX_, cur_);
    }

    return max(MX, MX_);
}