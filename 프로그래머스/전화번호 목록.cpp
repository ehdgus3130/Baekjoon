#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

bool solution(vector<string> phone_book) {
    unordered_set<string> S;
    S.reserve(phone_book.size() * 2);  // 리해시(재해싱) 줄이기 위한 여유 예약

    for (auto& num : phone_book) S.insert(num);

    for (const auto& num : phone_book) {
        string prefix;
        prefix.reserve(num.size()); //미리 num.size 만큼을 할당한다
        for (char c : num) {
            prefix.push_back(c);
            if (prefix.size() == num.size()) break; // 자기 자신은 제외
            if (S.find(prefix) != S.end()) { //prefix 만큼의 부분이 존재하는지 확인함
                return false; // 접두어 발견
            }
        }
    }
    return true;
}
