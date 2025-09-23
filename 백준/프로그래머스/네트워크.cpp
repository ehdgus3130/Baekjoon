#include <string>
#include <vector>
#include <queue>
using namespace std;


int solution(int n, vector<vector<int>> computers) {//BFS
    int answer = 1;
    int size = (int)computers.size();

    vector<bool> visited(n, false);
    queue<int> q;

    q.push(0);
    visited[0] = true;
    for (int i = 1; i < n; i++) {
        while (!q.empty()) {
            int cx = q.front(); q.pop();
            for (int i = 0; i < n; i++) {
                if (computers[cx][i] && !visited[i]) {
                    q.push(i); visited[i] = true;
                }
            }
        }
        if (!visited[i]) { q.push(i); answer++; }
    }


    return answer;
}