#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int check(string a, string b)
{
    int cnt = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == b[i]) cnt++;
    }
    return cnt;
}

int solution(string begin, string target, vector<string> words) {
    auto it = find(words.begin(), words.end(), target);
    if (it == words.end()) { return 0; }
    //-> 조건상 이부분은 바로 예외처리가 가능한 부분 
    int answer = 0;
    size_t a = (int)begin.size();
    size_t b = (int)words.size();

    vector<bool> visited(words.size(), false);
    queue<pair<string, int>> q;
    q.push({ begin, 0 });
    //-> 이부분 생각을 제대로 못했음

    while (!q.empty()) {
        string cur = q.front().first;
        int step = q.front().second;
        q.pop();

        if (cur == target) return step;

        for (int i = 0; i < b; i++)
        {
            if (check(words[i], cur) == (a - 1) && visited[i] == false)
            { //-> 변수 넣을때는 제대로 보고 넣자
                visited[i] = true;
                q.push({ words[i],step + 1 });
            }
        }
    }
    return 0;
}