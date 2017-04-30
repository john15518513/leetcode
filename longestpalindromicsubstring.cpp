class Solution {
public:
    Solution(): maxLen(0) {}
    string longestPalindrome(string s) {
        if (s.length() < 2) return s;
        for (int i = 0; i < s.length()-1; i++) {
            maxPalindrome(s, i, i);
            maxPalindrome(s, i, i+1);
        }
        return res;
    }
    void maxPalindrome(string &s, int i, int j) {
        while (true) {
            if (i < 0 or j >= s.length() or s[i] != s[j]) return;
            if (s[i] == s[j]) {
                
                if (j-i+1 > maxLen) {
                    maxLen = j-i+1;
                    res = s.substr(i, j-i+1);
                }
                i--;
                j++;
            }
        }
    }
private:
    int maxLen;
    string res;
};
