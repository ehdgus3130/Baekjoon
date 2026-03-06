#include <vector>
#include <algorithm>
using namespace std;

static int hungarianMin(const vector<vector<int>>& cost) {
    int n = (int)cost.size() - 1; // cost is (n+1)x(n+1)
    const int INF = 1e9;

    vector<int> u(n + 1, 0), v(n + 1, 0), p(n + 1, 0), way(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
        p[0] = i;
        int j0 = 0;
        vector<int> minv(n + 1, INF);
        vector<char> used(n + 1, false);

        do {
            used[j0] = true;
            int i0 = p[j0];
            int delta = INF, j1 = 0;

            for (int j = 1; j <= n; ++j) {
                if (used[j]) continue;
                int cur = cost[i0][j] - u[i0] - v[j];
                if (cur < minv[j]) {
                    minv[j] = cur;
                    way[j] = j0;
                }
                if (minv[j] < delta) {
                    delta = minv[j];
                    j1 = j;
                }
            }

            for (int j = 0; j <= n; ++j) {
                if (used[j]) {
                    u[p[j]] += delta;
                    v[j] -= delta;
                }
                else {
                    minv[j] -= delta;
                }
            }
            j0 = j1;
        } while (p[j0] != 0);

        do {
            int j1 = way[j0];
            p[j0] = p[j1];
            j0 = j1;
        } while (j0 != 0);
    }

    // min cost = -v[0]
    return -v[0];
}

int maxMatchSum(const vector<int>& cu,
    const vector<int>& cv,
    const vector<vector<int>>& dp) {
    int a = cu.size();
    int b = cv.size();
    int K = max(a, b);
    if (K == 0) return 0;

    int maxW = 0;
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            maxW = max(maxW, dp[cu[i]][cv[j]]);
        }
    }
    vector<vector<int>> cost(K + 1, vector<int>(K + 1, maxW));

    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            int w = dp[cu[i - 1]][cv[j - 1]];
            cost[i][j] = maxW - w;
        }
    }
    int minCost = hungarianMin(cost);
    int maxSum = K * maxW - minCost;
    return maxSum;
}

//입력 간선 g1/g2는 (부모/자식이 섞여 들어올 수 있어) 무방향으로 만든 뒤 루트 1에서 DFS로 방향을 잡아 children[u]와 postorder를 생성합니다
void buildRooted(int n,
    vector<vector<int>>& edges,
    vector<vector<int>>& children, //u 자식들만 담을 리스트
    vector<int>& post)
{
    vector<vector<int>> adj(n + 1);
    adj.assign(n + 1, {});
    for (int i = 0; i < edges.size(); i++) {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }

    children.assign(n + 1, {});
    vector<int> parent(n + 1, 0); //각 트리에서의 부모
    vector<int> it(n + 1, 0); //인접 리스트를 어디까지 봤는지

    vector<int> st; //DFS용
    st.push_back(1);
    parent[1] = -1;

    while (!st.empty()) {
        int u = st.back();
        if (it[u] < adj[u].size()) { //보지 않은 인접 노드가 존재한다
            int v = adj[u][it[u]++];
            if (v == parent[u]) continue; //부모로 돌아가는 거면 무시
            parent[v] = u;
            st.push_back(v); //부모 설정 후 내려감
        }
        else { //인접 노드 다 봄
            st.pop_back();
            post.push_back(u);
        }
    }

    for (int v = 2; v <= n; v++) {
        int p = parent[v];
        children[p].push_back(v);
    }

    for (int u = 1; u <= n; u++) {
        sort(children[u].begin(), children[u].end());
    }
}


// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n1, vector<vector<int>> g1, int n2, vector<vector<int>> g2) {
    int answer = 0;

    vector<vector<int>> c1, c2;
    vector<int> post1, post2;
    post1.clear(); post2.clear();

    buildRooted(n1, g1, c1, post1);
    buildRooted(n2, g2, c2, post2);

    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

    for (int iu = 0; iu < post1.size(); iu++) {
        int u = post1[iu];
        for (int iv = 0; iv < post2.size(); iv++) {
            int v = post2[iv];
            int match = maxMatchSum(c1[u], c2[v], dp);
            dp[u][v] = 1 + match;
        }
    }

    return dp[1][1];
}