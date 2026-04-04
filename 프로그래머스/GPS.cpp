#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9;

int solution(int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log) {
    vector<vector<int>> gr(n + 1);

    for (int i = 0; i < m; i++) {
        int a = edge_list[i][0];
        int b = edge_list[i][1];
        gr[a].push_back(b);
        gr[b].push_back(a);
    }

    vector<vector<int>> dp(k, vector<int>(n + 1, INF));
    dp[0][gps_log[0]] = 0;

    for (int t = 1; t < k; t++) {
        for (int v = 1; v <= n; v++) {
            int cost = (gps_log[t] == v ? 0 : 1);

            if (dp[t - 1][v] != INF) {
                dp[t][v] = min(dp[t][v], dp[t - 1][v] + cost);
            }

            for (int i = 0; i < gr[v].size(); i++) {
                int prev = gr[v][i];
                if (dp[t - 1][prev] == INF) continue;
                dp[t][v] = min(dp[t][v], dp[t - 1][prev] + cost);
            }
        }
    }

    if (dp[k - 1][gps_log[k - 1]] == INF) return -1;
    return dp[k - 1][gps_log[k - 1]];
}