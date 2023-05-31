#include<iostream>
#include<string>
using namespace std;

int main() {
	string N;
	cin >> N;

	for (int i = 0; i < N.size(); i++) {
		for (int j = i; j < N.size(); j++) {
			int cur;
			if (N[i] <  N[j]) {
				cur = N[i];
				N[i] = N[j];
				N[j] = cur;
			}
		}
	}
	cout << N;
}
