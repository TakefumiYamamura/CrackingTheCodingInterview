#include <iostream>
#include <algorithm>

using namespace std;

int func1(int h, int w){
	if(h % 3 == 0|| w % 3 == 0){
		return 0;
	}
	return min(h, w);
}

int func2(int h, int w){
	int min_dif = h * w;
	if(w % 2 == 0){
		for (int i = 1; i < h; ++i)
		{
			min_dif = min(abs(w * i - w / 2 * (h - i)), min_dif); 
		}
	}else{
		for (int i = 1; i < h; ++i)
		{
			int max_dif = max(abs( (w+1) / 2 * (h - i) - w / 2 * (h - i)) , max(abs(w * i - w / 2 * (h - i)), abs(w * i - (w+1) / 2 * (h - i))));
			min_dif = min(max_dif, min_dif);
		}
	}
	return min(min_dif, func2(w, h));
}


int main(){
	cin >> h >> w;
	cout << min(func1(h, w), func2(h, w) ) << endl;
}