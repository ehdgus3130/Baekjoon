#include <string>
#include <vector>
using namespace std;
/* 20분까지

     ( ) 개수가 같다 => 균형 잡힌
     ( ) 짝도 맞다 => 올바른
*/

string reverse(string str) {
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '(') str[i] = ')';
        else str[i] = '(';
    }
    return str;
}

string dfs(string p) {
    if (p.size() == 0) return p;

    bool balance = true, right = true;
    int cnt = 0, idx = 0, sum = 0;

    while (balance && idx < p.size()) {
        if (p[idx] == '(') { cnt++; sum += 1; }
        else { cnt--; sum -= 1; }

        if (sum < 0) right = false;

        if (cnt == 0) balance = false;
        else idx++;
    }

    string u = p.substr(0, idx + 1);
    string v = p.substr(idx + 1);

    if (right) {
        return u + dfs(v);
    }
    else {
        return "(" + dfs(v) + ")" + reverse(u.substr(1, u.size() - 2));
    }
}


string solution(string p) {
    string answer = "";
    int n = p.size();

    answer = dfs(p);
    return answer;
}