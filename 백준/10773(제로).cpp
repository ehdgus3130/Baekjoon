#include<iostream>
using namespace std;
#define MAX	100001

template<class T>
class Stack {
private:
	T* stack;
	int top;
	int capacity;
public:
	Stack(int StackCapacity);
	bool IsEmpty() const;	//원소수 0 -> true else -> false
	T& Top()const;		//탑 원소
	void Push(const T& item);	//삽입
	void Pop();		//제거

	int Sum();
};
template<class T>
Stack<T>::Stack(int StackCapacity) : capacity(StackCapacity) {
	if (StackCapacity < 0) throw"capacity must be >0";
	stack = new T[StackCapacity];
	top = -1;
}
template<class T>
bool Stack<T>::IsEmpty()const { return top == -1; }
template<class T>
T& Stack<T>::Top()const {
	if (IsEmpty()) throw"Stack Is Empty";
	return stack[top];
}
template<class T>
void Stack<T>::Push(const T& item) {
	stack[++top] = item;
}
template<class T>
void Stack<T>::Pop() {
	if (IsEmpty())throw "stack is empty";
	stack[top--].~T();		//T에 대한 파괴자!!!!!!!!!!!!!!!!!!
}

template<class T>
int Stack<T>::Sum() {
	if (IsEmpty()) return 0;
	int sum = 0;
	for (int i = 0; i <= top; i++) {
		sum += stack[i];
	}
	return sum;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	int k, n;
	cin >> k;
	Stack<int>arr(MAX);
	try{
		for (int i = 0; i < k; i++) {
			cin >> n;
			switch (n)
			{
			case 0:
				arr.Pop();
				break;
			default:
				arr.Push(n);
				break;
			}
		}
		cout << arr.Sum();
		return 0;
	}
	catch (string h) {
		cout << h;
	}
}
