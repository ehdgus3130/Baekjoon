#include <string>
#include <vector>

using namespace std;
/*
[type, r1, c1, r2, c2, degree]
type 1 attack / 2 heal
(r1, c1) ~ (r2, c2)

*/
int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    int n = board.size();
    int m = board[0].size();

    vector<vector<long long>> gr(n + 1, vector<long long>(m + 1, 0));


    for (int i = 0; i < skill.size(); i++) {
        int dy = skill[i][1], dy_ = skill[i][3];
        int dx = skill[i][2], dx_ = skill[i][4];

        long long degree = skill[i][0] == 1 ? -skill[i][5] : skill[i][5];

        gr[dy][dx] += degree;
        if (dy_ + 1 <= n) gr[dy_ + 1][dx] -= degree;
        if (dx_ + 1 <= m) gr[dy][dx_ + 1] -= degree;
        if (dy_ + 1 <= n && dx_ + 1 <= m) gr[dy_ + 1][dx_ + 1] += degree;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 1; j < m; j++)
            gr[i][j] += gr[i][j - 1];
    }

    for (int j = 0; j < m; j++) {
        for (int i = 1; i < n; i++)
            gr[i][j] += gr[i - 1][j];
    }



    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            long long hp = (long long)board[i][j] + gr[i][j];
            if (hp > 0) answer++;
        }
    }
    return answer;
}