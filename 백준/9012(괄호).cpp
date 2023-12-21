#include<iostream>
#include<stack>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	int n;
	char arr[51];
	cin >> n;
	for (int i = 0;i <n; i++) {
		cin >> arr;
		stack<char> bag;
		for (int i = 0; arr[i] != NULL; i++) {
			if (i == 0 || bag.size() ==0 )bag.push(arr[i]);
			else {
				if (bag.top() == '(' && bag.top() != arr[i]) {
					bag.pop();
				}
				else {
					bag.push(arr[i]);
				}
			}
		}
		if (bag.empty()) cout << "YES" << "\n";
		else cout << "NO"<< "\n";
		
	}
}