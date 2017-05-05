class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        dfs(word, 0, "", 0);
        return res;
    }
    
    void dfs(string &word, int pos, string path, int cnt) {
        if (pos == word.length()) {
            if (cnt > 0) path += to_string(cnt);
            res.push_back(path);
            return;
        }
        dfs(word, pos+1, path, cnt+1);
        dfs(word, pos+1, path + (cnt>0? to_string(cnt) : "") + word[pos], 0);
    }
private:
    vector<string> res;
};
