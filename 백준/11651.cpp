#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {

	int N;
	cin >> N;
	vector<pair<int, int>> arr(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i].second >> arr[i].first;
	}

	sort(arr.begin(), arr.end());

	for (int i = 0; i < N; i++) {
		cout << arr[i].second << " " << arr[i].first << "\n";
	}
}