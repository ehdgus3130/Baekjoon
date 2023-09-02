#include<iostream>
using namespace std;

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	int a, b, n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		for (int j = (a > b ? b : a); j >0 ; j--) {
			if (a % j == 0 && b % j == 0) {
				cout << a*b/j << "\n";
				break;
			}
		}
	}
}