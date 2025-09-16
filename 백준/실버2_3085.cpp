#include <iostream>
using namespace std;
int Maxcnt = 0;
int n;
bool Arrow = true; //True row ,false cols 

void Updatecnt(int input) {
	Maxcnt = Maxcnt > input ? Maxcnt : input;
}

void Search(char ** bom,int row,int cols,int cnt) {
	Updatecnt(cnt);
	if (cnt == 0) {
		if ((row != n-1) && (bom[row][cols] == bom[row + 1][cols])) {
			Arrow = true;
			Search(bom, row + 1, cols, ++cnt);
			cnt = 0;
		}
		
		
		if ((cols != n - 1) && (bom[row][cols] == bom[row][cols + 1])) {
			Arrow = false;
			Search(bom, row, cols + 1, ++cnt);
			cnt = 0;
		}
		

		if ((row != n - 1) && (cols != n - 1)) {
			if (bom[row][cols] == bom[row + 1][cols + 1]) {
				Updatecnt(++cnt);
				cnt = 0;
				return;
			}
		}
		
	}
	else {
		if (Arrow && row != n - 1) {
			if (bom[row][cols] == bom[row + 1][cols]) {
				Search(bom, row + 1, cols, ++cnt);
			}
			
		}
		else if(!Arrow && cols != n - 1) {
			if (bom[row][cols] == bom[row][cols + 1]) {
				Search(bom, row, cols + 1, ++cnt);
			}
			
		}
		
		if((row != n - 1 && cols != n - 1) ){
			if ((bom[row][cols] == bom[row + 1][cols + 1])) {
				if (Arrow && row != n - 2) {
					if ((bom[row][cols] == bom[row + 2][cols]))
						Search(bom,row + 2,cols,cnt + 2);
					else if((bom[row][cols] == bom[row][cols + 2]))
						Search(bom, row, cols + 2, cnt + 2);
				}
				Updatecnt(++cnt);
				cnt = 0;
				return;
			}

		}
	}
	cnt = 0;
	return;
}


int main() {
	int count =0;

	cin >> n;
	char **ans = new char*[n];


	for (int i = 0; i < n; i++){
		ans[i] = new char[n];
		for (int j = 0; j < n; j++) {
			cin >> ans[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			Search(ans, i, j,0);
		}
	}

	cout << Maxcnt + 1;
}