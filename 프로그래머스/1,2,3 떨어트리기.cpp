#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long LL;

vector<int> solution(vector<vector<int>> edges, vector<int> target) {
    vector<int> answer;

    int n = target.size();
    int m = edges.size();
    vector<vector<int>> gr(n + 1, vector<int>());

    //1. 우선 모든 내용들을 단방향 그래프로 만들어준다
    for (int i = 0; i < m; i++) {
        gr[edges[i][0]].push_back(edges[i][1]);
    }

    for (int i = 1; i < gr.size(); i++) {
        if (!gr[i].empty()) sort(gr[i].begin(), gr[i].end());
    }

    //2. 리프노드인지의 확인을 위해 따로 벡터로 만들어준다
    vector<int> isLeaf(n + 1, 0); //리프노드인지 확인 용도
    vector<int> leaves; //리프 노드들의 인덱스 

    for (int i = 1; i <= n; i++) {
        if (gr[i].empty()) {
            isLeaf[i] = 1;
            leaves.push_back(i);
        }
    }
    //2-1. 만약 리프노드(점수가 있을수밖에없음)가 아닌데 0점인경우
    for (int i = 1; i <= n; i++)
    {
        if (!isLeaf[i] && target[i - 1] != 0) return { -1 };
    }

    //3. 리프노드들에 대한 초기 점수들을 초기화함
    vector<int> nextIdx(n + 1, 0);
    vector<int> cnt(n + 1, 0);

    vector<char> sat(n + 1, 0);
    int satCount = 0;
    int leafCount = leaves.size();
    for (int i = 0; i < leafCount; i++) {
        int v = leaves[i];
        if (target[v - 1] == 0) { sat[v] = 1; satCount++; }
    }

    //4. 람다 함수를 통해 새롭게 추가하는 경우
    //   cnt 에대한 현재 가능상태를 확인해준다
    /*
        [&] : 바깥 변수들을 참조로 가져옴
        int v : 매개변수
        {...} : 본문
    */
    auto updSat = [&](int v) {
        bool prev = sat[v];
        bool now;
        int c = cnt[v];
        int t = target[v - 1];
        if (t == 0) now = (c == 0);
        else if (c == 0) now = false;
        else now = (c <= t && t <= 3 * c);
        if (prev != now) {
            sat[v] = now;
            satCount += (now ? 1 : -1);
        }
        };

    //5. 하나씩 넣어보자
    vector<int> order;
    while (satCount < leafCount) {
        int u = 1;
        while (!gr[u].empty()) { //리프노드가 나올때까지
            int idx = nextIdx[u];
            int v = gr[u][idx];
            idx++;
            if (idx == gr[u].size()) idx = 0;
            nextIdx[u] = idx;
            u = v;
        }
        order.push_back(u);
        cnt[u]++;

        if (cnt[u] > target[u - 1]) return { -1 }; //현재 할당치보다 더 높은 경우 탈락
        updSat(u);
    }

    //6. 
    vector<int> remCnt = cnt;
    vector<long long> remSum(n + 1, 0);
    for (int i = 1; i <= n; i++) remSum[i] = target[i - 1];

    //7. order에 들어간 리프노드들의 순서를 보며 최종 확인
    answer.reserve(order.size());

    for (int t = 0; t < order.size(); t++) {
        int vtx = order[t];
        int chosen = -1;
        for (int v = 1; v <= 3; v++) {
            if (remSum[vtx] < v) continue;
            int rc = remCnt[vtx] - 1;
            long long rs = remSum[vtx] - v;

            bool ok;
            if (rc == 0) ok = (rs == 0);
            else ok = (rc <= rs && rs <= 3LL * rc);

            if (ok) { chosen = v; break; }
        }
        if (chosen == -1) return { -1 };

        answer.push_back(chosen);
        remCnt[vtx]--;
        remSum[vtx] -= chosen;
    }

    return answer;
}
/*
    람다함수 추가 공부
    1.
    auto add = [](int a, int b) {
        return a + b;
    };

    int x = add(3, 4); // 7


    2.
    int cnt = 0;

    auto inc = [&]() {
        cnt++;          // 바깥 변수 cnt를 변경
    };

    inc();
    inc();
    // cnt == 2
*/