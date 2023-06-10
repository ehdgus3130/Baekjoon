#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(nullptr);

	int n, m, temp = 0;
	cin >> n >> m;
	vector<string> s(n);
	vector<string> p(m);

	for (int i = 0; i < n; i++)
		cin >> s[i];
	for (int i = 0; i < m; i++)
		cin >> p[i];

	sort(s.begin(), s.end());

	for (int i = 0; i < m; i++) {
		int left = 0;
		int right = n - 1;
		while (left <= right) {
			int mid = (left + right) / 2;

			if (s[mid] == p[i]) {
				temp++;
				break;
			}
			else if (s[mid] > p[i]) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
	}

	cout << temp;
}
