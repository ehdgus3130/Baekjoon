#include<iostream>
using namespace std;

int main() {
	int a, b, c, d, e, f, x, y;
	cin >> a >> b >> c >> d >> e >> f;

	for (int i = -999; i <= 999; i++) {
		for (int j = -999; j <= 999; j++) {
			x = i; y = j;
			if ((a * x) + (b * y) == c && (d * x) + (e * y) == f) { cout << x << " " << y; }
		}
	}
}
//https://www.acmicpc.net/problem/19532
//19532번: 수학은 비대면강의입니다
