#include<iostream>
using namespace std;

int main() {	//3 5 7 9 11 13 15 17 19 21
	long long n,sum=3;
	int i = 1;
	cin >> n;
	while (sum < n) {
		sum += (2*(i+1)+1);
		i++;
	}
	cout << i;
}