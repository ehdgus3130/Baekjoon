#include<iostream>
#include<stack>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);

	stack<int> line;		//���� ��Ȳ
	stack<int> cur;			//�ٽ� �ټ��¹��
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