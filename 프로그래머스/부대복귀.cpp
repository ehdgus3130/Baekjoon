#include <string>
#include <vector>
#include <queue>
using namespace std;

/*
복귀는 s 원소 순서대로 복귀
1 2 3 4 5
2 4   5 2
4 5   1 4
  1
큐를 돌면서 최소를 찾아간다
*/
vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer(sources.size(), -1);

    vector<vector<int>> gr(n + 1, vector<int>());

    for (int i = 0; i < roads.size(); i++) {
        gr[roads[i][0]].push_back(roads[i][1]);
        gr[roads[i][1]].push_back(roads[i][0]);
    }

    for (int i = 0; i < sources.size(); i++) {

        queue<int> q;
        vector<int> visited(n + 1, -1); //오는데 걸린 시간을 쓰자

        q.push(sources[i]);
        visited[sources[i]] = 0;

        while (!q.empty()) {
            int num = q.front(); q.pop();

            if (gr[num].size() == 0) { visited[destination] = -1; break; }

            if (num == destination) break;

            for (int j = 0; j < gr[num].size(); j++) {
                if (visited[gr[num][j]] != -1) continue;

                q.push(gr[num][j]);
                visited[gr[num][j]] = visited[num] + 1;
            }
        }
        answer[i] = visited[destination];
    }
    return answer;
}