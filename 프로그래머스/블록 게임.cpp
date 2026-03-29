#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;
vector<bool> canDel;
vector<int> dx{ 1,0,-1,0 };
vector<int> dy{ 0,1,0,-1 };
const int INF = 1e9;

void removeBlock(vector<vector<int>>& board, int num) {
    int n = board.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == num) {
                board[i][j] = 0;
            }
        }
    }
}

bool canRemove(vector<vector<int>>& board, int num) {
    int n = board.size();
    vector<pair<int, int>> block;
    int minX = INF, minY = INF, maxX = -1, maxY = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == num) {
                block.push_back({ i, j });
                minX = min(minX, j);
                minY = min(minY, i);
                maxX = max(maxX, j);
                maxY = max(maxY, i);
            }
        }
    }
    if (block.size() != 4) return false;

    for (int i = minY; i <= maxY; i++) {
        for (int j = minX; j <= maxX; j++) {

            if (board[i][j] == num) continue;
            else if (board[i][j] != 0) return false;
            else if (board[i][j] == 0) {
                int cnt = 0;
                for (int cur = i - 1; cur >= 0; cur--) { if (board[cur][j] != 0) return false; }
            }
        }
    }
    return true;
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    int n = board.size();

    while (true) {
        bool removed = false;

        set<int> numbers;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] != 0) numbers.insert(board[i][j]);
            }
        }

        for (int x : numbers) {
            if (canRemove(board, x)) {
                removeBlock(board, x);
                answer++;
                removed = true;
            }
        }

        if (!removed) break;
    }


    return answer;
}