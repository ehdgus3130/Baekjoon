#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<int> a) {
    int answer = 0;
    int n = a.size();

    vector<vector<int>> cnt(n + 1, vector<int>());
    unordered_map<int, int> freq;
    freq.reserve(n * 2);

    for (int i = 0; i < n; i++) { freq[a[i]]++; }

    int best = 0;

    for (auto& kv : freq) {
        int x = kv.first;

        int fx = kv.second;
        if (fx < 2) continue;
        if (best >= fx * 2) continue;

        int pairs = 0;
        for (int i = 0; i < n - 1;) {
            if (a[i] == a[i + 1]) { i++; continue; }
            if (a[i] == x || a[i + 1] == x) { pairs++; i += 2; }
            else i++;
        }
        best = max(pairs * 2, best);
    }


    return best;
}