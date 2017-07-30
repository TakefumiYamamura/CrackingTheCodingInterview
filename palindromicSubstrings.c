int ans;

int recursive(char* s, int i, int j) {
    int len = strlen(s);
    if(i < 0 || j >= len) return;
    if(s[i] == s[j]) {
        // printf("%c %c %d \n", s[i], s[j], ans);
        ans++;
    } else {
        return;
    }
    recursive(s, --i, ++j);
}

int countSubstrings(char* s) {
    ans = 0;
    int len = strlen(s);
    for(int i = 0; i < len; i++) {
        recursive(s, i, i);
        recursive(s, i, i+1);
    }
    return ans;
}
