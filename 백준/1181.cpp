#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int pos, n, min = 51;
	string cur;
	cin >> n;
	vector<string> arr(n);
	vector<string> ans;


	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	while (arr.size()!=0) {
		for (int j = 0; j < arr.size(); j++) {
			if (min > arr[j].size()) {
				min = arr[j].size();
				cur = arr[j];
				pos = j;
			}
			else if (min == arr[j].size()) {
				if (cur == arr[j]) {	//���� �����ߺ�
					arr.erase(arr.begin() + j);
					continue;
				}
				else {
					if (cur < arr[j]) {		//���������� cur�� �� �ռ���?
						continue;
					}
					else {
						cur = arr[j];
						pos = j;
					}
				}
			}
		}
		arr.erase(arr.begin() + pos);
		ans.push_back(cur);
		min = 51;
	}
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << "\n";
}

/*
#include <iostream>
#include <algorithm>
using namespace std;

int cmp(string a, string b) {
	// 1. ���̰� ���ٸ�, ����������
	if (a.length() == b.length()) {
		return a < b;
	}
	// 2. ���̰� �ٸ��ٸ�, ª�� ������
	else {
		return a.length() < b.length();
	}
}

// ������ ũ�⶧���� ���������� ����
string word[20000];

int main() {
	int N;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> word[i];
	}

	sort(word, word + N, cmp);

	for (int i = 0; i < N; i++) {
		// �ߺ��� ��� �ѹ��� ���
		if (word[i] == word[i - 1]) {
			continue;
		}
		cout << word[i] << "\n";
	}

	return 0;
}
*/