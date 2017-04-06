class Solution {
public:
	string fractionToDecimal(int numerator, int denominator){
		long long nume = numerator;
		long long deno = denominator;
		string ans = "";
		if( (nume < 0 && deno > 0) || (nume > 0 && deno < 0) ){
			ans += "-";
		}
		if(nume < 0) nume *= -1;
		if(deno < 0) deno *= -1;
		ans += to_string(nume / deno);
		nume = nume - deno * (nume / deno);
		map<long long, int> hash;
		if(nume != 0) ans += ".";
		while(nume != 0){
			nume *= 10;
			if(hash.find(nume) != hash.end()){
				ans.insert(hash[nume], "(");
				ans += ")";
				break;
			}
			hash[nume] = ans.length();
			ans += to_string(nume / deno);
			nume = nume - deno * (nume / deno) ;
		}
		return ans;
	}
};