#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

class TowerOfHanoi
{
private:
	vector<stack<int> > sts;
	unordered_map<int, int> hash;
public:
	TowerOfHanoi(int _n){
		sts.resize(3);
		for (int i = _n; i > 0; --i)
		{
			sts[0].push(i);
		}
	}

	stack<int> reverese_stack(stack<int> origin){
		stack<int> new_stack;
		while(!origin.empty()){
			new_stack.push(origin.top() );
			origin.pop();
		}
		return new_stack;
	}

	void check_stack(int i){
		stack<int> tmp = sts[i];
		tmp = reverese_stack(tmp);
		while(!tmp.empty()){
			cout << tmp.top() << " ";
			tmp.pop();
		}
		cout << endl;
	}

	void print_state(){
		for (int i = 0; i < 3; ++i)
		{
			cout << i << " : ";
			check_stack(i);
		}
		cout << endl;
	}

	void move_one(int from, int to){
		int top = sts[from].top();
		sts[from].pop();
		sts[to].push(top);
	}

	int hanoi(int n, int from, int work, int target){
		if(n == 0) return 0;
		// memo化
		if(hash.find(n) != hash.end()) return hash[n];
		int count = 0;

		// workにn-1個の山を動かす
		count += hanoi(n-1, from, target, work);
		// target に一番大きい円盤を渡す。
		move_one(from, target);
		count++;
		print_state();
		count += hanoi(n-1, work, from, target);
		hash[n] = count;
		return count;
	}

};


int main(){
	TowerOfHanoi toh = TowerOfHanoi(10);
	toh.print_state();
	cout << toh.hanoi(10, 0, 1, 2) << endl;
}
