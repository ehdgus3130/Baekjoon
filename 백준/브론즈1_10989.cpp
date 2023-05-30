#include<iostream>
#include<vector>
using namespace std;
//배열에 넣고 배열을 정렬하는것이 아닌 범위안에 표시를 한후 하나씩 확인해줌
int b;
int n;
vector<int> a(10001, 0);

int main() {
	ios::sync_with_stdio(0);	//C와 c++간의 표준 스트림 동기화를 끊는다는 것과,
	cin.tie(0);					//기본적으로 cout에 종속적인 cin을 cout으로부터 끊는다는 것
	cout.tie(0);
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> b;
		a[b] += 1;
	}
	for (int i = 0; i < 10001; i++) {
		if (a[i] > 0) {
			for (int j = 0; j < a[i]; j++) {

				cout << i << '\n';
			}
		}
	}
}
