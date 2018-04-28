class Solution {
    
public:
    string addBoldTag(string s, vector<string>& dict) {
        vector<bool> dp(s.size(), false);
        for (int i = 0, end = 0; i < s.size(); i++) {
            for (auto &word: dict) {
                if (word == s.substr(i, word.size())) {
                    end = max(end, i+int(word.size()));
                }
            }
            dp[i] = end > i;
        }
        string res = "";
        for (int i = 0; i < s.size(); i++) {
            if (!dp[i]) {
                res.push_back(s[i]);
                continue;
            }
            int j = i;
            while (j < s.length() && dp[j]) j++;
            res = res + "<b>" + s.substr(i, j-i) + "</b>";
            i = j - 1;
        }
        return res;
    }
    
};
