#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Screen
{
private:
	int size;
	int full_bit;
	vector<int> screen;
public:
	Screen(int size_) : size(size_) {
		screen = vector<int>(size_, 0);
		for (int i = 0; i < 8; ++i)
		{
			full_bit = full_bit | (1 << i);
		}
	}
	void show(){
		for (int i = 0; i < size; ++i)
		{
			for (int j = 0; j < 8; ++j)
			{
				if(!(screen[i] >> j & 1) ){
					cout << "0";
				}else{
					cout << "-";
				}
			}
			cout << endl;
		}
		cout << endl;
	}

	void drawLine(int x1, int x2, int y){
		if(x1 > x2) swap(x1, x2);
		screen[y] = screen[y] | (full_bit >> (8 - x2 - 1) & full_bit << x1);
	}
	
};


int main(){
	Screen s = Screen(8);
	s.drawLine(2, 4, 5);
	s.show();
	s.drawLine(2, 4, 7);
	s.show();
	s.drawLine(3, 6, 1);
	s.show();
	s.drawLine(0, 5, 7);
	s.show();
}