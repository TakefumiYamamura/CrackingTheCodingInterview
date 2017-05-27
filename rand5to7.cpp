#include <iostream>
#include <map>

using namespace std;

int rand5(){
	return rand() % 5;
}

int rand7(){
	while(true){
		int r1 = rand5() * 2;
		int r2 = rand5();
		if(r2 == 4) continue;
		int r3 = r2 % 2;
		if(r1 + r3 >= 7) continue;
		return r1 + r3;
	}
}

int main(){
	map<int ,int> mp;
	for (int i = 0; i < 10000000; ++i)
	{
		mp[rand7()]++;
	}
	for(auto itr = mp.begin(); itr != mp.end(); itr++){
		cout << itr->first << " " << itr->second / 10000000.0 << endl;
	}
}
