#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n, m;
	cin >> n >> m;

	vector<int> A(n);
	vector<int> B(m);
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> B[i];
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	int fromA = 0;
	for (int i = 0; i < n; i++) {
		int left = 0;
		int right = m - 1;
		while (left <= right) {
			int mid = (left + right) / 2;

			if (A[i] == B[mid]) {
				fromA++;
				break;
			}
			else if (A[i] <= B[mid]) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
	}
	int fromB = 0;
	for (int i = 0; i < m; i++) {
		int left = 0;
		int right = n - 1;
		while (left <= right) {
			int mid = (left + right) / 2;

			if (B[i] == A[mid]) {
				fromB++;
				break;
			}
			else if (B[i] <= A[mid]) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
	}
	cout << (n - fromA) + (m - fromB) << "\n";

}
/*		setÀÎ°æ¿ì
int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int a,b,c;
	set<int> s;
	cin>>a>>b;

	for(int i=0;i<a;i++){
		cin>>c;
		s.insert(c);
	}

	while(b--){
		cin>>c;
		if(s.find(c)==s.end()){
			a++;
		}
		else{
			a--;
		}
	}
	cout<<a;
}*/