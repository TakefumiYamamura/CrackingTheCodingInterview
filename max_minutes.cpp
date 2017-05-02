#include <iostream>
#include <vector>

using namespace std;

class max_minutes
{
private:
	vector<int> array;
public:
	max_minutes(vector<int> _array){
		array = _array;
	}

	int exec(){
		vector<vector<int> > dp = vector<vector<int> >(array.size(), vector<int>(2, 0));
		if(array.size() == 0) return 0;
		int ans = 0;
		dp[0][0] = 0;
		dp[0][1] = array[0];

		for (int i = 1; i < array.size(); ++i)
		{
			dp[i][0] = max(dp[i-1][1], dp[i-1][0]);
			dp[i][1] = dp[i-1][0] + array[i];
		}

		return max(dp[array.size() - 1][0], dp[array.size() - 1][1]);
	}

	int exec_wo_space(){
		if(array.size() == 0) return 0;
		int un_select = 0;
		int select = array[0];
		for (int i = 1; i < array.size(); ++i)
		{
			int new_un_select = max(un_select, select);
			int new_select = un_select + array[i];
			un_select = new_un_select;
			select = new_select;
		}
		return max(un_select, select);
	}

	
};

int main(){
	vector<int> tmp{30, 15, 60, 75, 45, 15, 15, 45};
	max_minutes mm = max_minutes(tmp);
	cout << mm.exec() << endl;
	cout << mm.exec_wo_space() << endl;
}
