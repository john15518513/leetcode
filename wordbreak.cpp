class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.length(), false);
        //for (auto &word: wordDict) cout << word.length() << endl;
        for (int i = 0; i < s.length(); i++) {
            for (auto &word: wordDict) {
                //cout << "hi" << endl;
                if ( (i-int(word.length()) == -1 or 
                     (i-int(word.length()) >= 0 and dp[i-int(word.length())] == true) ) and 
                     word == s.substr(i-int(word.length())+1, int(word.length()))  ) {
                    dp[i] = true;
                    break;
                }
                //cout << "hiend" << endl;
            }
        }
        return dp.back();
    }
};
