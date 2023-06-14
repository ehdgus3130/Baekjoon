#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m, sum = 0;
	cin >> n >> m;
	vector<string>listen(n);
	for (int i = 0; i < n; i++)
		cin >> listen[i];

	sort(listen.begin(), listen.end());
	vector<string>listensee;

	for (int i = 0; i < m; i++) {
		string a;
		cin >> a;
		int left = 0;
		int right = n - 1;
		while (left <= right) {
			int mid = (left + right) / 2;

			if (a == listen[mid]) {
				listensee.push_back(a);
				break;
			}
			else if (a <= listen[mid]) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
	}
	sort(listensee.begin(), listensee.end());
	cout << listensee.size() << "\n";
	for (int i = 0; i < listensee.size(); i++) {
		cout << listensee[i] << "\n";
	}

}