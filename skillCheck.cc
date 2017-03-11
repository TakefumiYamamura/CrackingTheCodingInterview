#include <vector>
#include <iostream>

#define MAX 1000000
#define ll long long

using namespace std;
class Solver
{
public:
    Solver(){
        ll n;
        while(cin >> n){
            exec(n);
        }
    }

    void exec(ll n){
        ll ans = 0;
        if(n % 2 == 0){
            cout << 0 << endl;
        }else{
            cout << ((2 * MAX -1)/n +1)/ 2 << endl;
        }
    }
};

int main(){
    Solver s = Solver();
}
