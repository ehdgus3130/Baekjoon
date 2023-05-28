#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int max=0;
	cin.tie(0);
	vector<int> a(5);
	for (int i = 0; i < a.capacity(); i++) {
		cin >> a[i];
		max += a[i];
	}
	sort(a.begin(), a.end());
	cout << max / 5 << endl << a[2];
}