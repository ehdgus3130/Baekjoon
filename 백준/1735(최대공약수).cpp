#include<iostream>
using namespace std;

int gcd(int a, int b) {
	if (b == 0) return a;
	return(gcd(b, a % b));
}

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	int a, b, c, d;
	int deno, num, a1, a2;
	cin >> a >> b;
	cin >> c >> d;
	a1 = gcd(b, d);
	deno = (b*d) / a1;
	/*for (int j = (d > b ? d : b); j > 0; j--) {	//최소 공배수
		if (b % j == 0 && d % j == 0) {
			deno= b * d / j;
			break;
		}
	}*/

	num = (a * (deno / b)) + (c * (deno / d));
	a2 = gcd(deno, num);
	deno = deno / a2;
	num = num / a2;
	/*for (int i = (deno > num ? deno : num); i >0; i--) {
		if (deno % i == 0 && num % i == 0) {
			deno = deno/i;
			num = num / i;
			break;
		}
	}*/
	cout << num << " " << deno;
}