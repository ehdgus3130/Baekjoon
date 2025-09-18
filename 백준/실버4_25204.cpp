#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(string a, string b) {
	int i = 0, j = 0;
	while (i < a.size() && j < b.size()) {
		char c1 = a[i], c2 = b[j];

		if (c1 == c2) { ++i; ++j; continue; } //다음 인덱스로 이동

		if (c1 == '-' && c2 != '-') return false; //- 확인하기
		if (c1 != '-' && c2 == '-') return true;

		if (isalpha(c1) && isalpha(c2)) { //숫자인지 확인하기

			char l1 = tolower((unsigned char)c1); //대소문자 구분하기
			char l2 = tolower((unsigned char)c2);
			if (l1 != l2) return l1 < l2;
			//if (c1 != c2) return c1 < c2;
			return c1 < c2;
		}
		else {
			return c1 < c2;
		}
	}

	//if (isalpha(c1) && isalpha(c2)) {
	//	char l1 = tolower((unsigned char)c1);
	//	char l2 = tolower((unsigned char)c2);
	//	if (l1 != l2) return l1 < l2;   // 대소문자 무시 비교
	//	return c1 < c2;



	//if (b.find(a)) return true;
	//else if(a.find(b)) return false;
	//
	//auto it = a.find("-");
	//auto it2 = b.find("-");

	//if (a.substr(it) == b.substr(it2)) {
	//	return a.substr(it + 1) > b.substr(it2 + 1);
	//}
	return a.size() < b.size();
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	string cmd;

	int max, cnt;

	cin >> max;
	for (int i = 0; i < max; i++)
	{
		cin >> cnt;
		vector<string> words(cnt);
		for (int j = 0; j < cnt; j++) {
			cin >> words[j];
		}
		sort(words.begin(), words.end(), compare);
		for (auto& s : words) cout << s << '\n';
	}
}