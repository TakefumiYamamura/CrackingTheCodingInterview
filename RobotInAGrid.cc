#include <iostream>
#include <vector>
#include <cmath>
#include <stack>

using namespace std;

template <typename T> class MyQueue{
private:
	stack<T> st1;
public:
	MyQueue();
	~MyQueue();
	void push(T value);
	T pop(T value);
};

template <typename T>
MyQueue<T>::MyQueue(){

}

template <typename T>
MyQueue<T>::~MyQueue(){}

template <typename T>
void MyQueue<T>::push(T value){
	st1.push(value);
}

template <typename T>
T MyQueue<T>::pop(T value){
	stack<T> st2;
	while(!st1.empty()){
		st2.push(st1.top());
		st1.pop();
	}
	st2.pop()
	while(!st2.empty()){
		st1.push(st2.top());
		st2.pop();
	}
}

int main(){
	MyQueue<int> testQueue;
	testQueue.push(1);
	testQueue.push(2);
	testQueue.push(3);
	testQueue.push(4);
	cout << testQueue.pop() << endl;
	cout << testQueue.pop() << ednl;
	testQueue.push(5);
	for (int i = 0; i < 3; ++i)
	{
		cout << testQueue.pop() << endl;
	}
}
