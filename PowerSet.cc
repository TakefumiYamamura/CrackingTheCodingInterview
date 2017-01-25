#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

class PowerSet{
private:
	int n;
public:
	PowerSet(int n_){
		n = n_;
	}
	void exec(){
		for (int i = 0; i < 1 << n; ++i)
		{
			int tmp = i;
			int itr = 0;
			while(tmp > 0){
				if(tmp & 1){
					cout << "a" << itr <<" ";
				}
				tmp = tmp >> 1;
				itr++;
			}
			cout << endl;
		}
	}
};

int main(){
	PowerSet ps = PowerSet(5);
	ps.exec();
}
