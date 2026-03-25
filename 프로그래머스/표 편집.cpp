#include <string>
#include <vector>
#include <stack>
using namespace std;

string solution(int n, int k, vector<string> cmd) {
    string answer(n, 'X');

    vector<int> prev(n, -1);
    vector<int> next(n, -1);
    vector<bool> alive(n, true);
    stack<vector<int>> st;

    for (int i = 0; i < n; i++) {
        if (i != 0) prev[i] = i - 1;
        if (i != n - 1) next[i] = i + 1;
    }


    int cur = k;

    for (string s : cmd) {
        char c = s[0];

        switch (c) {
        case 'D': {
            int num = stoi(s.substr(2));
            while (num > 0) { cur = next[cur]; num--; }
            break;
        }
        case 'U': {
            int num = stoi(s.substr(2));
            while (num > 0) { cur = prev[cur]; num--; }
            break;
        }
        case 'C': {
            st.push({ cur, prev[cur], next[cur] });
            alive[cur] = false;

            int p = prev[cur];
            int nx = next[cur];

            if (p != -1) next[p] = nx;
            if (nx != -1) prev[nx] = p;

            if (nx != -1) cur = nx;
            else cur = p;

            break;
        }
        case 'Z': {
            vector<int> last = st.top(); st.pop();

            int idx = last[0];
            int p = last[1];
            int nx = last[2];

            alive[idx] = true;

            if (p != -1) next[p] = idx;
            if (nx != -1) prev[nx] = idx;

            prev[idx] = p;
            next[idx] = nx;
            break;
        }
        }
    }

    for (int i = 0; i < n; i++) {
        if (alive[i]) answer[i] = 'O';
    }


    return answer;
}