#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	unsigned int n, cur;
	cin.tie(0);
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());

	for(int i=0;i < n;i++)
		cout << a[i]<<'\n';//endl�� ����� ������ ���۸� flush�ϱ� ������ �ſ� ����
}
//sort�� ��� �ð����⵵ O(nLogn)