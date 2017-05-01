#include <iostream>
#include <vector>

using namespace std;

class histogramVolume
{
private:
	vector<int> array;
public:
	histogramVolume(vector<int> _array){
		array = _array;
	}

	void exec(){
		int ans = 0;
		int max_idx = 0;
		int max_v = 0;
		for (int i = 0; i < array.size(); ++i)
		{
			if(max_v < array[i]){
				max_v = array[i];
				max_idx = i;
			}
		}
		int l = 0;
		for (int i = 1; i < array.size(); ++i)
		{
			if(array[l] < array[i] || i == max_idx){
				ans += array[l] * (i - l - 1);
				l = i;

				if(i == max_idx) break;
			}else{
				ans -= array[i];
			}
		}
		int r = array.size() - 1;
		for (int i = array.size() - 2; i >= 0; --i)
		{
			if(array[r] < array[i] || i == max_idx){
				ans += array[r] * (r - i - 1);
				r = i;
				if(i == max_idx) break;
			}else{
				ans -= array[i];
			}
		}
		cout << ans << endl;
	}

	
};

int main(){
	vector<int> tmp{1, 0, 4, 0, 0, 5, 0, 0, 5, 0, 5, 0, 1, 0, 0, 0};
	histogramVolume hv = histogramVolume(tmp);
	hv.exec();
}
