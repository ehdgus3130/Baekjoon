#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);

	int n, m, a;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	cin >> m;
	vector<int>brr(m);
	for (int i = 0; i < m; i++)
		cin >> brr[i];

	vector<int>crr(m,0);
	sort(arr.begin(), arr.end());

	for (int i = 0; i < m; i++) {
		int left = 0;
		int right = n - 1;
		while (left <=right) {
			int mid = (left + right) / 2;
			if  (arr[mid] == brr[i]) {
				crr[i] = 1;
				break;
			}
			else if (arr[mid] > brr[i]) {
				right = mid-1;
			}
			else  {
				left = mid + 1;
			}
		}
	}

	for (int i = 0; i < m; i++) {
		cout << crr[i] << " ";
	}
}
