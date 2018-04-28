class Solution {
public:
    bool isPalindrome(string s) {
        string res = "";
        for (int i = 0; i < s.length(); i++) {
            if (isalnum(s[i])) {
                res += tolower(s[i]);
            }
        }
    
        return res == string(res.rbegin(), res.rend());
        
    }
};
