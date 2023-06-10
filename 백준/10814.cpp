#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool compare(pair<int, string> a, pair<int, string> b)
{
	return a.first < b.first;
}
int main() {
	int n;
	int c;
	string a;
	cin >> n;

	vector<pair<int, string>> arr(n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i].first >> arr[i].second;
	}

	stable_sort(arr.begin(), arr.end(), compare);
	/*
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n-1 - i; j++) {
			if (arr[j].first > arr[j+1].first) {
				c = arr[j].first;
				a = arr[j].second;
				arr[j] = arr[j + 1];
				arr[j + 1].first = c;
				arr[j + 1].second = a;
			}
			else if (arr[j].first == arr[j+1].first) {
				continue;
			}
		}
	}*/

	for (int i = 0; i < n; i++)
		cout << arr[i].first << " " << arr[i].second << "\n";

}