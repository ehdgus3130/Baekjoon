#include<vector>
#include<queue>
using namespace std;
int dx[] = { 0,1,0,-1 };// R D L U
int dy[] = { 1,0,-1,0 };

int solution(vector<vector<int>> maps) //DFS
{
    int n = (int)maps.size(), m = (int)maps[0].size();
    int dir = 0, x, y; //0 1 2 3


    vector<vector<int>> graph(n, vector<int>(m, 1));
    vector<vector<bool>> visited(n, vector<bool>(m, 0));
    queue<pair<int, int>> q;

    q.push({ 0,0 });
    visited[0][0] = true;

    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        if (x == n - 1 && y == m - 1) return graph[x][y];
        q.pop();
        for (dir = 0; dir < 4; dir++)
        {
            int cx = x + dx[dir];
            int cy = y + dy[dir];
            if (cx < 0 || cy < 0 || cx >= n || cy >= m) continue;
            if (maps[cx][cy] && !visited[cx][cy])
            {
                q.push({ cx,cy }); visited[cx][cy] = 1;
                graph[cx][cy] = graph[x][y] + 1;
            }
        }
    }
    return -1;
}