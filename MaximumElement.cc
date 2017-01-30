#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

class Solver{
private:
	int n;
	stack<int> s;
	stack<int> maxS;
public:
	Solver(){
		cin >> n;
		maxS.push(-1);
	}
	void exec(){
		for (int i = 0; i < n; ++i)
		{
			int type;
			cin >> type;
			if(type == 1){
				int ele;
				cin >> ele;
				s.push(ele);
				if(ele >= maxS.top()) maxS.push(ele);
			}else if(type == 2){
				if(s.top() == maxS.top()){
					maxS.pop();
				}
				s.pop();
			}else{
				cout << maxS.top() << endl;
			}
		}
	}
};

int main(){
	Solver s = Solver();
	s.exec();
}
