#include <string>
#include <vector>

using namespace std;

int dfs(vector<int>& numbers, int target, int i, int sum) {
    if (i == (int)numbers.size()) return (sum == target) ? 1 : 0;

    int PLUS = dfs(numbers, target, i + 1, sum + numbers[i]);

    int MINUS = dfs(numbers, target, i + 1, sum - numbers[i]);

    return PLUS + MINUS;
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    return dfs(numbers, target, 0, 0);
}