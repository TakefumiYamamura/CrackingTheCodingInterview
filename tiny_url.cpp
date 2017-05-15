class Solution {
private:
    unordered_map<string, string> long_short_url;
    unordered_map<string, string> short_long_url;
    string dict = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
public:

    string createRandaom(){
        string tinyUrl = "http://tinyurl.com/";
        for (int i = 0; i < 6; ++i)
        {
            tinyUrl += dict[rand() % 62];
        }
        return tinyUrl;
    }

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string tinyUrl;
        if(long_short_url.find(longUrl) != long_short_url.end()) return long_short_url[longUrl];
        while(true){
            tinyUrl = createRandaom();
            if(short_long_url.find(tinyUrl) == short_long_url.end()) break; 
        }
        short_long_url[tinyUrl] = longUrl;
        long_short_url[longUrl] = tinyUrl;
        return tinyUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        if(short_long_url.find(shortUrl) == short_long_url.end()) return "-1";
        return short_long_url[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
