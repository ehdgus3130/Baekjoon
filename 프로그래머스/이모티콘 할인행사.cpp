#include <string>
#include <vector>

using namespace std;
vector<int> answer;
vector<vector<int>> U;
vector<int> E;

/*
    dfs(idx):
    if idx == emoticons.size():
        현재 할인 조합으로 가입자 수, 매출 계산
        정답 갱신
        return

    for discount in {10,20,30,40}:
        choice[idx] = discount
        dfs(idx + 1)
*/

void dfs(int idx, vector<int>& choice) {
    if (idx == E.size()) {
        int application = 0;
        int sum = 0;

        for (int i = 0; i < U.size(); i++) {
            int tmp_sum = 0;
            for (int j = 0; j < E.size(); j++) {
                if (U[i][0] > choice[j]) continue;
                tmp_sum += E[j] * (100 - choice[j]) / 100;
            }
            if (tmp_sum < U[i][1]) { sum += tmp_sum; }
            else { application++; }
        }
        if (application > answer[0]) {
            answer[0] = application;
            answer[1] = sum;
        }
        else if (application == answer[0] && sum > answer[1]) {
            answer[1] = sum;
        }
        return;
    }
    for (int i : {10, 20, 30, 40}) {
        choice[idx] = i;
        dfs(idx + 1, choice);
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    answer.resize(2, 0);
    U = users;
    E = emoticons;
    vector<int> tmp(emoticons.size(), 0);
    dfs(0, tmp);
    return answer;
}