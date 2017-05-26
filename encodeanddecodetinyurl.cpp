class Solution {
public:
    Solution(): dict("0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"){}
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string key = "";
        do{
            for (int i = 0; i < 6; i++) key += dict[rand()%62];
        }while(map.find(key) != map.end());
        map[key] = longUrl;
        return "http://tinyurl.com/"+key;
        
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        auto it = shortUrl.find_last_of("/");
        return map[shortUrl.substr(it+1, 6)];
    }
private:
    string dict;
    unordered_map<string, string> map;
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
