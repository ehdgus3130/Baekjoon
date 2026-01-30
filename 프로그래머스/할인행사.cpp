#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    const int W = 10;
    const int n = (int)discount.size();
    if (n < W) return 0;

    // 필요한 수량 표
    unordered_map<string, int> need; //정렬 안되고 중복 안됨
    for (size_t i = 0; i < want.size(); ++i) {
        need[want[i]] = number[i];
    }

    // 현재 10일 윈도우 내 수량 표
    unordered_map<string, int> win;

    // 초기 윈도우 [0, W)
    for (int i = 0; i < W; ++i) {
        ++win[discount[i]];
    }

    auto ok = [&]()->bool {
        // want에 있는 품목이 모두 need 이상인지 확인
        for (const auto& kv : need) {
            auto it = win.find(kv.first);
            int have = (it == win.end() ? 0 : it->second);
            if (have < kv.second) return false;
        }
        return true;
        };

    int answer = 0;
    if (ok()) ++answer;

    // 슬라이딩: 윈도우를 하루씩 앞으로
    for (int i = W; i < n; ++i) {
        // 들어오는 날(i), 나가는 날(i-W)
        ++win[discount[i]];
        auto& outCnt = win[discount[i - W]];
        if (--outCnt == 0) win.erase(discount[i - W]); // 깔끔하게 유지(선택)

        if (ok()) ++answer;
    }

    return answer;
}
