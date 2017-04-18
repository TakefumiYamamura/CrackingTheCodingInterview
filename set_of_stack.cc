#include <stack>
#include <vector>
#include <cassert>
#include <iostream>

using namespace std;

template<typename T>
class set_of_stack
{
private:
	int size;
	vector<stack<T> > stack_array;

public:
	set_of_stack(int _size){
		size = _size;
	}

	T top(){
		return stack_array[stack_array.size() - 1].top();
	}

	T top_at(int index){
		assert(index < stack_array.size());
		return stack_array[index].top();
	}

	void push(T val){
		if(stack_array.size() == 0 || stack_array[stack_array.size() - 1].size() ==  size){
			stack<T> new_stack;
			new_stack.push(val);
			stack_array.push_back(new_stack);
		}else{
			stack_array[stack_array.size() - 1].push(val);
		}

	}

	void pop(){
		assert(stack_array.size() != 0);
		stack_array[stack_array.size() - 1].pop();
		if(stack_array[stack_array.size() - 1].empty()){
			auto itr = stack_array.end();
			itr--;
			stack_array.erase(itr);
		}
	}

	bool empty(){
		return stack_array.size() == 0;
	}

};

int main(){
	set_of_stack<int> sts(4);
	cout << sts.empty() << endl;
	for (int i = 0; i < 15; ++i)
	{
		sts.push(i);
		cout << sts.top() << " ";
		sts.pop();
	}
	cout << endl;
	cout << sts.empty() << endl;

	for (int i = 0; i < 15; ++i)
	{
		sts.push(i);
		cout << sts.top() << " ";
	}

	for (int i = 0; i < 5; ++i)
	{
		cout << sts.top_at(i) << " ";
	}
	cout << endl;

}
