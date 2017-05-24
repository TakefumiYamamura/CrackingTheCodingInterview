#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class encode_xml
{
private:
	unordered_map<string, int> dic;
public:
	encode_xml(unordered_map<string, int> _dic) : dic(_dic) {}
	string encode(string str){
		string decode_str = "";
		string tmp = "";
		for (int i = 0; i < str.length(); ++i)
		{
			if(str[i] == ' ') continue;
			tmp += str[i];
			// cout << tmp << endl;
			if(str[i] == '<'){
				if(str[i+1] == '/'){
					if(tmp != "<"){
						tmp[tmp.length() - 1] = ' ';
						decode_str += tmp;
					}
					decode_str += "0 ";
					string tmp_str = "";
					while(str[i] != '>'){
						i++;
					}
					tmp = "";
				} else {
					tmp = "";
				}
			}else if (dic.find(tmp) != dic.end()){
				decode_str +=  to_string(dic[tmp]) + " ";
				tmp = "";
			}else if( tmp == "="){
				int count = 0;
				i++;
				string tmp_str = "";
				while(count < 2){
					if(str[i] == '`' ){
						count++;
					}else{
						tmp_str += str[i];
					}
					i++;
				}
				i--;
				decode_str += tmp_str + " ";
				tmp = "";
			}else if(tmp == ">"){
				decode_str += "0 ";
				tmp = "";
			}
		}
		decode_str += ".";
		return decode_str;
	}
};

int main(){
	unordered_map<string, int> dic;
	dic["family"] = 1;
	dic["person"] = 2;
	dic["firstName"] = 3;
	dic["lastName"] = 4;
	dic["state"] = 5;
	encode_xml ex = encode_xml(dic);
	string str = "<family lastName=`McDowell` state=`CA`> <person firstName=`Gayele`>Some Message</person> </family>";
	cout << str << endl;
	cout << ex.encode(str) << endl;
}