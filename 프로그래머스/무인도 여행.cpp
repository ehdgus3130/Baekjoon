#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> dx{ 1, 0, -1, 0 };
vector<int> dy{ 0, 1, 0, -1 };

vector<int> solution(vector<string> maps) {
    vector<int> answer;

    int n = maps.size();
    int m = maps[0].size();

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (maps[i][j] == 'X' || visited[i][j]) continue;

            q.push({ i, j });
            visited[i][j] = true;
            int cnt = maps[i][j] - '0';

            while (!q.empty()) {
                auto [y, x] = q.front(); q.pop();

                for (int dir = 0; dir < 4; dir++) {
                    int cy = y + dy[dir];
                    int cx = x + dx[dir];

                    if (cy < 0 || cy >= n || cx < 0 || cx >= m) continue;
                    if (visited[cy][cx]) continue;
                    if (maps[cy][cx] == 'X') continue;

                    q.push({ cy, cx });
                    visited[cy][cx] = true;
                    cnt += (maps[cy][cx] - '0');

                }
            }
            answer.push_back(cnt);
        }
    }

    if (answer.size() == 0) answer.push_back(-1);
    sort(answer.begin(), answer.end());
    return answer;
}