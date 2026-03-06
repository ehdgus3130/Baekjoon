#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> dx{ 1,0,-1,0 };
vector<int> dy{ 0,1,0,-1 };

const int INF = 1e9;

struct Node {
    int cost;
    int y;
    int x;
    int dir;
};

struct Cmp {
    bool operator()(const Node& a, const Node& b) const {
        return a.cost > b.cost; // min-heap
    }
};

int solution(vector<vector<int>> board) {
    int answer = 0;

    int n = board.size();

    vector<vector<vector<int>>> dist(n, vector<vector<int>>(n, vector<int>(4, INF)));

    priority_queue<Node, vector<Node>, Cmp> pq;

    for (int dir = 0; dir < 4; dir++) {
        dist[0][0][dir] = 0;
        pq.push({ 0, 0, 0, dir });
    }

    while (!pq.empty()) {
        Node cur = pq.top(); pq.pop();
        int cost = cur.cost;
        int y = cur.y;
        int x = cur.x;
        int dir = cur.dir;

        if (cost != dist[y][x][dir]) continue;

        for (int ndir = 0; ndir < 4; ndir++) {
            int cx = dx[dir] + x;
            int cy = dy[dir] + y;

            if (cy < 0 || cy >= n || cx < 0 || cx >= n) continue;
            if (board[cy][cx] == 1) continue;

            int add = 100;
            if (ndir != dir) add += 500;

            int ncost = cost + add;

            if (ncost < dist[cy][cx][ndir]) {
                dist[cy][cx][ndir] = ncost;
                pq.push({ ncost, cy, cx, ndir });
            }
        }
    }

    int ans = INF;

    for (int dir = 0; dir < 4; dir++)
        ans = min(ans, dist[n - 1][n - 1][dir]);

    return ans;
}