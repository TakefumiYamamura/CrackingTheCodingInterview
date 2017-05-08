#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;


void all_length(int k, int a, int b){
	unordered_set<int> st;
	for (int i = 0; i <= k; ++i)
	{
		st.insert(a * i + b * (k - i) ); 
	}
	for (auto itr = st.begin(); itr != st.end(); ++itr)
	{
		cout << *itr << " ";
	}
	cout << endl;

}

int main(){
	all_length(20, 21, 14);
}
