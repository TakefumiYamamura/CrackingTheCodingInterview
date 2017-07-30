public class Solution {
    int count = 0;
    String str;
    private void palindromeCheck(int i, int j) {
        if(i < 0 || j >= str.length()) return;
        if(str.charAt(i) == str.charAt(j) ) {
            count++;
        } else {
            return;
        }
        palindromeCheck(--i, ++j);
    }
    
    public int countSubstrings(String s) {
        str = s;
        for(int i = 0; i < str.length(); i++) {
            palindromeCheck(i, i);
            palindromeCheck(i, i+1);
        }
        return count;
    }
}
