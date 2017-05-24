#include <iostream>
#include <vector>
using namespace std;

class shuffle_array
{
private:
	int n;
	vector<int> array;
public:
	shuffle_array(int _n){
		n = _n;
		for (int i = 0; i < n; ++i)
		{
			array.push_back(i);
		}
	}
	void print(){
		for (int i = 0; i < n; ++i)
		{
			cout << array[i] << " ";
		}
		cout << endl;
	}
	void shuffle(){
		srand((unsigned) time(NULL));
		for (int i = n-1; i > 0 ; --i)
		{
			//0 ~ i 番目の乱数
			int r = rand() % (i + 1);
			swap(array[i], array[r]);
		}
	}
};


int main(){
	shuffle_array sa = shuffle_array(15);
	sa.print();
	sa.shuffle();
	sa.print();
}
