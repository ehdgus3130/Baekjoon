#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a (n);
	for (int i = 0; i < a.capacity(); i++) cin >> a[i];
	sort(a.begin(), a.end());
	for (int i = 0; i < a.capacity(); i++) cout << a[i] << endl;
}
