#include <iostream>
#include <vector>

#define ll long long

using namespace std;


//this program is solved by greedy way.
ll number_of_twos(ll n){
	n++;
	ll tmp = 1;
	ll ans = 0;
	while(n/tmp != 0){
		ans += n/(tmp * 10) * tmp;
		if(n % (tmp * 10) > 2 * tmp){
			ans += min(n % (tmp * 10) - 2 * tmp , tmp);
		}
		tmp *= 10;
	}
	return ans;

}

ll number_of_ones(ll n){
	n++;
	ll tmp = 1;
	ll ans = 0;
	while(n/tmp != 0){
		ans += n/(tmp * 10) * tmp;
		if(n % (tmp * 10) > tmp){
			ans += min(n % (tmp * 10) - tmp , tmp);
		}
		tmp *= 10;
	}
	return ans;
}


int main(){
	ll tmp;
	cin >> tmp;
	cout << number_of_ones(tmp) << endl;
	cout << number_of_twos(25) << endl;
}
