#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n, k, x;
	cin >> n >> k;
	vector<int> num(n);

	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	sort(num.begin(), num.end());

	cout << num[n - (k)];
}
