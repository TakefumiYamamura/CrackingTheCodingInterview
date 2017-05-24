class Solution {
public:
    void reverseWords(string &s) {
        string new_s = "";
        string tmp = "";
        bool flag = true;


        string remove_s = "";
        for (int i = 0; i < s.length(); ++i)
        {
            if(s[i] == ' '){
                while(i < s.length() && s[i] == ' '){
                    i++;
                }
                i--;
                remove_s += " ";
 
            }else{
                remove_s += s[i];
            }
        }
        s = remove_s;

        for (int i = 0; i < s.length(); ++i)
        {
            if(s[i] == ' '){
                while(i < s.length() && s[i] == ' '){
                    i++;
                }
                i--;
                if(flag){
                    new_s += tmp;
                }else{
                    new_s += tmp + " ";
                }
                flag = false;
                tmp = "";
            }else{
                tmp += s[i];
            }
        }
        cout << tmp << endl;
        if(tmp != ""){
            if(new_s == ""){
                new_s = tmp;
            }else{
                new_s = tmp + " " + new_s;
            }
        }
        s = new_s; 
        if(s.size() == 0) return;
        int i = 0; 
        while(s.size() > 0 && s[0] == ' '){
            s.erase(s.begin());
        }
        while(s.size() > 0 && s[s.size() - 1] == ' '){
            s.erase(s.end() - 1);
        }
    }
};