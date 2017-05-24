#include <iostream>
#include <stack>

using namespace std;

template<typename T>
class sort_stack
{
private:
	stack<T> st;
public:
	sort_stack(){}
	void push(T val){
		stack<T> sub_st;
		bool flag = true;
		while(!st.empty()){
			T next = st.top();
			if(next >= val){
				st.push(val);
				flag = false;
				break;
			}
			st.pop();
			sub_st.push(next);
		}

		if(flag){
			st.push(val);
		}

		while(!sub_st.empty()){
			T next = sub_st.top();
			sub_st.pop();
			st.push(next);
		}
	}

	void pop(){
		st.pop();
	}

	T top(){
		T top = st.top();
		return top;
	}

	bool empty(){
		return st.empty();
	}	
};

int main(){
	sort_stack<int> st;
	st.push(1);
	st.push(50);
	st.push(-100);
	cout << st.top() << endl;
	st.push(3);
	st.push(900);
	while(!st.empty()){
		int tmp = st.top();
		st.pop();
		cout << tmp << " ";
	}
	cout << endl;
}
