#include<iostream>
#include<cmath>
using namespace std;

bool multiple(long long n)
{
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	long long a;
	cin >> n;

	for (long long i = 0; i < n; i++) {
		cin >> a;
		if (a >= 0 && a <= 2) cout << 2 << "\n";
		else if (a == 3)
			cout << 3 << "\n";
		else {
			while (!multiple(a))
				a++;
			cout << a << "\n";
		}
	}
}