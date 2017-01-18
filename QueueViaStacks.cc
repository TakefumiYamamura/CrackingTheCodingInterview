#include <iostream>
#include <vector>
#include <cmath>
#include <stack>

using namespace std;

template <class T> class MyQueue{
private:
	stack<T> st1;
public:
	MyQueue();
	~MyQueue();
	void push(T value);
	T pop();
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
T MyQueue<T>::pop(){
	stack<T> st2;
	while(!st1.empty()){
		st2.push(st1.top());
		st1.pop();
	}
	T ans = st2.top();
	st2.pop();
	while(!st2.empty()){
		st1.push(st2.top());
		st2.pop();
	}
	return ans;
}

int main(){
	MyQueue<int> testQueue;
	testQueue.push(1);
	testQueue.push(2);
	testQueue.push(3);
	testQueue.push(4);
	int pop1 = testQueue.pop();
	int pop2 = testQueue.pop();
	cout << pop1 << endl;
	cout << pop2 << endl;
	testQueue.push(5);
	for (int i = 0; i < 3; ++i)
	{
		int tmpPop = testQueue.pop(); 
		cout << tmpPop << endl;
	}
}
