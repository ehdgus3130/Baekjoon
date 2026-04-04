#include <string>
#include <vector>
#include <deque>
#include <utility>
using namespace std;

int n, m;

void Rotate(deque<int>& L, deque<deque<int>>& M, deque<int>& R) {
    if (m == 2) {
        int tmp = L.front();
        L.pop_front();
        R.push_front(tmp);

        tmp = R.back();
        R.pop_back();
        L.push_back(tmp);
        return;
    }

    int tmp = L.front();
    L.pop_front();

    M.front().push_front(tmp);

    tmp = M.front().back();
    M.front().pop_back();
    R.push_front(tmp);

    tmp = R.back();
    R.pop_back();

    M.back().push_back(tmp);

    tmp = M.back().front();
    M.back().pop_front();
    L.push_back(tmp);
}

void ShiftRow(deque<int>& L, deque<deque<int>>& M, deque<int>& R) {
    L.push_front(L.back());
    L.pop_back();

    R.push_front(R.back());
    R.pop_back();

    M.push_front(std::move(M.back()));
    M.pop_back();
}

vector<vector<int>> solution(vector<vector<int>> rc, vector<string> operations) {
    n = rc.size();
    m = rc[0].size();

    if (n == 1) {
        deque<int> row;
        for (int j = 0; j < m; j++) row.push_back(rc[0][j]);

        int rotateCnt = 0;
        for (const string& op : operations) {
            if (op[0] == 'R') rotateCnt++;
        }
        rotateCnt %= m;

        while (rotateCnt--) {
            row.push_front(row.back());
            row.pop_back();
        }

        vector<vector<int>> answer(1, vector<int>(m));
        for (int j = 0; j < m; j++) {
            answer[0][j] = row.front();
            row.pop_front();
        }
        return answer;
    }

    if (m == 1) {
        deque<int> col;
        for (int i = 0; i < n; i++) col.push_back(rc[i][0]);

        int cnt = operations.size() % n;
        while (cnt--) {
            col.push_front(col.back());
            col.pop_back();
        }

        vector<vector<int>> answer(n, vector<int>(1));
        for (int i = 0; i < n; i++) {
            answer[i][0] = col.front();
            col.pop_front();
        }
        return answer;
    }

    deque<int> L, R;
    deque<deque<int>> M;

    for (int i = 0; i < n; i++) {
        deque<int> tmp;
        L.push_back(rc[i][0]);
        R.push_back(rc[i][m - 1]);
        for (int j = 1; j <= m - 2; j++) {
            tmp.push_back(rc[i][j]);
        }
        M.push_back(std::move(tmp));
    }

    int idx = 0;
    int perimeter = 2 * n + 2 * m - 4;

    while (idx < operations.size()) {
        const string& op = operations[idx];
        int cnt = 0;

        while (idx < operations.size() && operations[idx] == op) {
            cnt++;
            idx++;
        }

        if (op[0] == 'S') {
            cnt %= n;
            while (cnt--) ShiftRow(L, M, R);
        }
        else {
            cnt %= perimeter;
            while (cnt--) Rotate(L, M, R);
        }
    }

    vector<vector<int>> answer(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        answer[i][0] = L.front();
        L.pop_front();

        for (int j = 1; j <= m - 2; j++) {
            answer[i][j] = M[i].front();
            M[i].pop_front();
        }

        answer[i][m - 1] = R.front();
        R.pop_front();
    }

    return answer;
}