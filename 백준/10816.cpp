#include<iostream>
#include <map>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m,a;
	cin >> n;
	map<int , int>card;
	for (int i = 0; i < n; i++) {
		int c;
		cin >> c;
		if (card.find(c) != card.end()) {	//중복입력
			card[c] += 1;
		}
		else {								//첫입력
			card.insert({ c, 1 });
		}
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> a;

		auto it =card.lower_bound(a);
		if (card.count(a))
			cout << card[a] << ' ';
		else
			cout << 0 << ' ';
	}
}