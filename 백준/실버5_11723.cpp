#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	string cmd;
	int max, min = 0, n;

	cin >> max;
	for (int i = 0; i < max; i++)
	{
		cin >> cmd;
		if (cmd == "add") {
			cin >> n;
			min |= (1 << n);
		}
		else if (cmd == "remove") {
			cin >> n;
			min &= ~(1 << n);
		}
		else if (cmd == "check") {
			cin >> n;
			cout << ((min & (1 << n)) ? 1 : 0) << '\n';
		}
		else if (cmd == "toggle") {
			cin >> n;
			min ^= (1 << n);
		}
		else if (cmd == "all") {
			min = (1 << 21) - 2;
			//for (int i = 1; i < 21; i++)
			//	min |= (1 << i);
		}
		else if (cmd == "empty") {
			min = 0;
			/*for (int i = 1; i < 21; i++)
				min = 0;*/
		}
	}
}