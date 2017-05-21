#include <stack>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

double calculator(string str){
	vector<string> rpn;
	stack<string> sym;
	cout << str << endl;
	for (int i = 0; i < str.length(); ++i)
	{
		switch(str[i]){
			case '+':
				while(!sym.empty()){
					rpn.push_back(sym.top());
					sym.pop();
				}
				sym.push("+");
				break;
			case '-':
				while(!sym.empty()){
					rpn.push_back(sym.top());
					sym.pop();
				}
				sym.push("-");
				break;
			case '*':
				while(!sym.empty() && (sym.top() == "*" || sym.top() == "/") ){
					rpn.push_back(sym.top());
					sym.pop();					
				}
				sym.push("*");
				break;
			case '/':
				while(!sym.empty() && (sym.top() == "*" || sym.top() == "/") ){
					rpn.push_back(sym.top());
					sym.pop();					
				}
				sym.push("/");
				break;
			default:
				string tmp = "";
				while(str[i] != '+' && str[i] != '-' && str[i] != '*' && str[i] != '/'){
					tmp += str[i];
					i++;
					if(i == str.length()) break;
				}
				i--;
				rpn.push_back(tmp);
				break;
		}	
	}

	while(!sym.empty()){
		rpn.push_back(sym.top());
		sym.pop();
	}

	for (int i = 0; i < rpn.size(); ++i)
	{
		cout << rpn[i] << " ";
	}
	cout << endl;
	stack<double> st;
	for (int i = 0; i < rpn.size(); ++i)
	{
		if(rpn[i] == "+"){
			double a1 = st.top();
			st.pop();
			double a2 = st.top();
			st.pop();
			st.push(a2 + a1);
		}else if(rpn[i] == "-"){
			double a1 = st.top();
			st.pop();
			double a2 = st.top();
			st.pop();
			st.push(a2 - a1);
		}else if(rpn[i] == "*"){
			double a1 = st.top();
			st.pop();
			double a2 = st.top();
			st.pop();
			st.push(a2 * a1);
		}else if(rpn[i] == "/"){
			double a1 = st.top();
			st.pop();
			double a2 = st.top();
			st.pop();
			st.push(a2 / a1);
		}else{
			st.push(stoi(rpn[i]) * 1.0);
		}		
	}
	return  st.top();

}

int main(){
	cout << calculator("2*3+5/6*3+15") << endl;
}
