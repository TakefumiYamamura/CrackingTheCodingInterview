#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std;
class Solver
{
public:
    int n;
    vector<int> array;
    //firstが今のmax secondが今の列の長さ
    vector<unordered_map<int, int> > dp;
    Solver(){
        cin >> n;
        for (int i = 0; i < n; ++i)
        {
            int tmp;
            cin >> tmp;
            array.push_back(tmp);
        }
    }

    void exec(){
        dp.resize(n+1);
        if(n == 0){
            cout << 0 << endl;
            return;
        }
        dp[0][array[0]] = 1;
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            dp[i][0] = 0;
            for (auto itr = dp[i].begin(); itr != dp[i].end(); ++itr)
            {
                // cout << itr->first << " " << itr->second << endl;
                if(i < n-1 && itr->first < array[i+1]){
                    dp[i+1][array[i+1]] = max(itr->second + 1, dp[i+1][array[i+1]]);
                }
                if(i < n-2 && itr->first < array[i+2]){
                    dp[i+2][array[i+2]] = max(itr->second + 1, dp[i+2][array[i+2]]);
                }
                if(i < n-3 && itr->first < array[i+3]){
                    dp[i+3][array[i+3]] = max(itr->second + 1, dp[i+3][array[i+3]]);
                }
            }
            for (auto itr = dp[i].begin(); itr != dp[i].end(); ++itr)
            {
                ans = max(itr->second, ans);
            }
            // cout << ans << " "<< endl;
            // cout << endl;
        }
        cout << ans << endl;
    }
};

int main(){
    Solver s = Solver();
    s.exec();
}
