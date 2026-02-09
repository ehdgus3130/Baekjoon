#include <string>
#include <vector>
#include <algorithm>
using namespace std;
/*
    Aidx 와 Bidx 를 비교함
*/
int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    int size = A.size();

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int a_ = 0, b_ = 0;
    while (b_ < size) {
        if (A[a_] < B[b_]) {
            answer++;
            a_++; b_++;
        }
        else {
            b_++;
        }

    }

    return answer;
}