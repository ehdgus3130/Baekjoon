#include<iostream>
#include<set>
#include<algorithm>
#include<string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string a;
	cin >> a;
	set<string> n;
	for (int i = 0; i < a.length(); i++) {
		for (int j = 0;j < a.length() -i; j++) {
			string cur = a.substr(j, i + 1);
			n.insert(cur);
		}
	}

	cout << n.size() << "\n";

}