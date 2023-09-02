#include<iostream>
#include<vector>
using namespace std;
#define MAX 1000000
vector<int> arr(MAX+1, 1);

void Eratos(int n) {					//�����佺�׳׽��� ü
	arr[0] = 0; arr[1] = 0;
	int sum = 0;
	if (n == 1) {
		cout << 1 << "\n";
		return;
	}
	else {
		for (int i = 2; i * i <= n; i++) {
			if (arr[i] == 0) continue;			//�ð� ������
			for (int j = i * i; j <= n; j += i) {
				arr[j] = 0;			//j idx is 0(not sosu)
			}
		}
	}
}


int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int t,n;
	cin >> t;
	Eratos(MAX);

	for (int i = 0; i < t; i++) {
		cin >> n;

		int sum = 0;
		for (int i = n; i >= n / 2; i--) {		//�Ҽ����� ���̰� ��������
			if (arr[i] && arr[n - i]) {			//�� �� ���ΰ�� ���ϸ� �ڵ����� ���̳���
				sum++;
			}
		}
		cout << sum << "\n";
	}
}