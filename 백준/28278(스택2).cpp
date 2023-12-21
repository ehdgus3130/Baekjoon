#include<iostream>
#include<stack>
using namespace std;
stack<int> arr;
int n, k, a;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> k;
		switch (k)
		{
		case 1:
			cin >> a;
			arr.push(a);
			break;
		case 2:
			if (arr.empty()) {
				cout << "-1\n";
			}
			else {
				cout << arr.top() << "\n";
				arr.pop();
			}
			break;
		case 3:
			cout << arr.size() << "\n";
			break;
		case 4:
			if (arr.empty()) {
				cout << "1\n";
			}
			else {
				cout << "0\n";
			}			
			break;
		case 5:
			if (arr.empty()) {
				cout << "-1\n";
			}
			else {
				cout << arr.top() << "\n";
			}
			break;
		}
	}
}
/*
class _Node {
	friend class _Stack;
private:
	int value;
	_Node* Next;
public:
	_Node() : Next(nullptr) {};
	_Node(int num) : value(num) {};
};

class _Stack {
private:
	_Node* Head;
	_Node* Tail;
public:
	_Stack() { Head = NULL; Tail = NULL; }
	void Push(int num);
	void Pop();
	void Many();
	bool IsEmpty();
	int Top();

};

void _Stack::Push(int num) {
	_Node* cur = new _Node(num);

	if (Head == NULL) {
		Head = Tail = cur;
	}
	else {
		_Node* temp = Head;
		while (temp->Next != NULL)
			temp = temp->Next;
		temp->Next = cur;
		Tail = cur;
	}
	Tail->Next = NULL;
}

void _Stack::Pop() {
	_Node* temp = Head;
	if (Head == nullptr){
		cout << -1;
		return;
	}
	if (Head == Tail) {
		cout << temp->value;
		Head = Tail = NULL;
		delete Head, Tail;
	}
	else {
		while (temp->Next != Tail) {
			temp = temp->Next;
		}
		cout << Tail->value;
		delete Tail;
		Tail = temp;
		Tail->Next = NULL;

	}
}

void _Stack::Many() {
	_Node* temp = Head;
	int i = 1;
	while (temp != Tail) {
		temp = temp->Next;
		i++;
	}
	cout << i;
}
bool _Stack::IsEmpty() {
	return !Head;
}
int _Stack::Top() {
	if (Head != NULL)
		return Tail ->value;
	else
		return -1;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	_Stack a;
	int n;
	int k;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> k;
		switch (k)
		{
		case 1:
			int c;
			cin >> c;
			a.Push(c);
			break;
		case 2:
			a.Pop();
			break;
		case 3:
			a.Many();
			break;
		case 4:
			cout << a.IsEmpty();
			break;
		case 5:
			cout << a.Top();
			break;
		}
	}
	
}*/