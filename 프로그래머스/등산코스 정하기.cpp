#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int INF = 1e9;

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> answer = { INF, INF };

    vector<vector<pair<int, int>>> gr(n + 1); //1-index

    for (const auto& it : paths) { // 이내용도 전달시 복사로 전달됨 주의할것
        gr[it[0]].push_back({ it[1],it[2] });
        gr[it[1]].push_back({ it[0],it[2] });
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n + 1, INF);
    vector<bool> isGate(n + 1, false);
    vector<bool> isSummit(n + 1, false);

    for (int num : gates) {
        dist[num] = 0;
        pq.push({ 0, num });
    }

    for (int num : gates) isGate[num] = true;
    for (int num : summits) isSummit[num] = true;

    while (!pq.empty()) {
        int curIntensity = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (curIntensity > dist[node]) continue;
        if (isSummit[node])continue;

        for (int i = 0; i < gr[node].size(); i++) {
            int nextNode = gr[node][i].first;
            int nextIntensity = max(gr[node][i].second, curIntensity);

            if (isGate[nextNode]) continue;

            if (nextIntensity < dist[nextNode]) {
                dist[nextNode] = nextIntensity;
                pq.push({ dist[nextNode], nextNode });
            }
        }
    }

    sort(summits.begin(), summits.end());

    for (int summit : summits) {
        if (dist[summit] < answer[1]) {
            answer[0] = summit;
            answer[1] = dist[summit];
        }
    }


    return answer;
}