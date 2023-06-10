#include<set>
#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

bool compare(int i, int j) {
	return j < i;
}

int main() {
	cin.tie(0);
	int n;
	cin >> n;
	set<string> log;
	for (int i = 0; i < n; i++){
		string a, b;
		cin >> a >> b;
		if (b == "enter") 
			log.insert(a);
		else
			log.erase(a);
	}
	for (auto i = log.rbegin(); i != log.rend(); i++)
		cout << *i << "\n";
}