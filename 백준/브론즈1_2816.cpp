#include <iostream>
using namespace std;
const int MAX = 500;
int curKBS2;
int curKBS1;
int cur;
void Find1() {
	if (curKBS1 < curKBS2) { // 3 3
		cur = 0;
		for (int i = 0; i < curKBS1; i++) { cout << 3; }
		curKBS1--;
		if (0 == curKBS1) {
			cur = 1;
		}
		else {
			cout << 2;
			for (int j = 0; j < curKBS1; j++) { cout << 4; }
		}
		return;
	}
	else { // 1 1 4
		for (int k = 0; k < curKBS1; k++) { cout << 1; }
		for (int l = 0; l < curKBS1; l++) { cout << 4; }
		curKBS2++;
		return;
	}
}

void Find2() {



	if (cur == 0) {
		for (int i = cur; i < curKBS2; i++) {
			cout << 1;
		}
		for (int j = cur + 1; j < curKBS2; j++) {
			cout << 4;
		}
	}
	else {
		for (int i = cur; i < curKBS2; i++) {
			cout << 3;
		}
		curKBS2--;
		if (curKBS2 == 1) return;
		cout << 2;
		for (int j = 1; j < curKBS2; j++) { cout << 4; }
	}
	return;
}

int main()
{
	int n;

	cin >> n;
	string ans[MAX];
	for (int i = 0; i < n; i++) {
		cin >> ans[i];
		if (ans[i] == "KBS1") curKBS1 = i;
		else if (ans[i] == "KBS2") curKBS2 = i;
	}

	Find1();
	Find2();
}