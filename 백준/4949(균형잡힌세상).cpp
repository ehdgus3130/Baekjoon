#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main() {
	string arr;
	stack <char> ar;
	while (1) {
		getline(cin, arr);
		if (arr[0] == '.') return 0;
		for (int i = 0; arr[i] != NULL; i++) {
			if (arr[i] == '.') break;
			if (arr[i] == '(' || arr[i] == '[') {
				ar.push(arr[i]);
			}
			else if (arr[i] == ']') {
				if (!ar.empty() && ar.top() == '[') ar.pop();
				else ar.push(arr[i]);
			}
			else if (arr[i] == ')') {
				if (!ar.empty() && ar.top() == '(') ar.pop();
				else ar.push(arr[i]);
			}

		}
		if (ar.empty()) cout << "yes" << "\n";
		else {
			cout << "no" << "\n";
			while (!ar.empty()) {
				ar.pop();
			}
		}
	}
}