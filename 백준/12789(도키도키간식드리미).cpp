#include<iostream>
#include<stack>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);

	stack<int> line;		//현재 상황
	stack<int> cur;			//다시 줄서는방법
	int n, k;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> k;
		line.push(k);
	}
	for (int i = 0; i < n; i++) {
		while(line[i] == i)
	}
}