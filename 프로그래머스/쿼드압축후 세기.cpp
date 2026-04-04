#include <string>
#include <vector>
using namespace std;
vector<vector<int>> A;
vector<int> answer;
void compress(int y, int x, int size) {
    bool isSame = true;
    int num = A[y][x];

    if (size == 1) {
        if (num == 1) answer[1]++;
        else answer[0]++;
        return;
    }

    int y_ = y + size;
    int x_ = x + size;

    for (int i = y; i < y_; i++) {
        for (int j = x; j < x_; j++) {
            if (num == A[i][j]) continue;
            isSame = false;
            break;
        }
    }

    if (!isSame) {
        compress(y, x, size / 2);
        compress(y + size / 2, x, size / 2);
        compress(y, x + size / 2, size / 2);
        compress(y + size / 2, x + size / 2, size / 2);
    }
    else {
        if (num == 1) answer[1]++;
        else answer[0]++;
    }
    return;
}


vector<int> solution(vector<vector<int>> arr) {
    answer.resize(2, 0);
    A = arr;
    int n = arr.size();

    compress(0, 0, n);


    return answer;
}