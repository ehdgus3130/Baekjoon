#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void compress(vector<int> a) {
	vector<int>b = a;
	sort(b.begin() , b.end());
	b.erase(unique(b.begin(), b.end()), b.end());	//unique ���ӵ� �ε����� �����ִ� �뵵
	for (int i = 0; i < a.size(); i++)
		cout << lower_bound(b.begin(), b.end(), a[i]) - b.begin() << " ";
}		//a[i]�� ���ų� ū ù ���� �ּҰ� ��ȯ

int main() {
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<int> arr(n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	compress(arr);
}