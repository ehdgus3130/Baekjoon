#include <string>
#include <vector>
#include <iostream>
#include <set>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer{ 0, 0 };
    int m = words.size();


    bool foundError = false;
    int cnt = 0;
    set<string> s;

    s.insert(words[0]);

    for (int i = 1; i < m; i++) {
        if (s.count(words[i]) > 0 || words[i - 1].back() != words[i].front()) {
            foundError = true;
            cnt = i + 1;
            break;
        }
        s.insert(words[i]);
    }

    if (foundError) {
        answer[0] = (cnt % n) == 0 ? n : (cnt % n);
        answer[1] = (cnt - 1) / n + 1;//cnt / n + cnt % n;
    }

    return answer;
}