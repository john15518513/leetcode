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

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words;
        for (auto &w: wordDict) words.insert(w);
        vector<bool> dp(s.length(), false);
        for (int i = 0; i < s.size(); i++) {
            for (int j = 1; j <= s.size(); j++) {
                if (j+i-1 >= s.size()) break;
                if ((i == 0 || dp[i-1] == true) and words.find(s.substr(i, j)) != words.end()) dp[i+j-1] = true;
            }
        }
        return dp.back();
    }
};
