#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

struct Node{
	string str;
	int leftNum;
	int rightNum;
};

class Parens{
public:
	int n;
	Parens(int n_){
		n = n_;
	}
	vector<string> exec(){
		Node start = {"", 0, 0};
		queue<Node> q;
		q.push(start);
		vector<string> ans;
		while(!q.empty()){
			Node cur = q.front();
			q.pop();
			if(cur.leftNum == n & cur.rightNum == n){
				ans.push_back(cur.str);
				continue;
			}
			if(cur.leftNum < n){
				Node next = {cur.str + "(", cur.leftNum + 1, cur.rightNum};
				q.push(next);
			}
			if(cur.rightNum < cur.leftNum){
				Node next = {cur.str + ")", cur.leftNum, cur.rightNum + 1};
				q.push(next);
			}
		}
		return ans;
	}
};


int main(){
	Parens p = Parens(5);
	vector<string> ans = p.exec();
	for (int i = 0; i < ans.size(); ++i)
	{
		cout << ans[i] << endl;
	}
}
