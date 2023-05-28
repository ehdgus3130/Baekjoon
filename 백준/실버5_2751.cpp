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
		cout << a[i]<<'\n';//endl은 출력할 때마다 버퍼를 flush하기 때문에 매우 느림
}
//sort의 경우 시간복잡도 O(nLogn)
