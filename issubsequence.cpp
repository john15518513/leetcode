class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (t.length() < s.length()) return false;
        int index = 0;
        for (int i = 0; i < t.length(); i++) {
            if(s[index] == t[i]) index++;
            if (index == s.length()) return true;
        }
        return index == s.length();
    }
};
