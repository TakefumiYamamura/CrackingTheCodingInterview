#include <vector>
#include <iostream>
#include <string>

using namespace std;
class Solver
{
public:
    Solver(){}
    string stringCompression(string str){
        string ans = "";
        if(str.length() == 1) return str;
        char before = str[0];
        int count = 1;
        for (int i = 1; i < str.length(); ++i)
        {
            if(before != str[i]){
                ans += before + to_string(count);
                count = 1;
                before = str[i];
            }else{
                count++;
            }
        }
        ans += before + to_string(count);
        if(ans.length() >= str.length()) return str;
        return ans;

    }
};

int main(){
    Solver s = Solver();
    cout << s.stringCompression("aaa") << endl;
    cout << s.stringCompression("abcde") << endl;
    cout << s.stringCompression("aaaabbbbbbccdeffff") << endl;
    cout << s.stringCompression("aaaabbbbbbccdeffffg") << endl;
}
