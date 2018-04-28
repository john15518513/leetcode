class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; i - j >= 0 and i + j < s.size() and s[i-j] == s[i+j]; j++) res++;
            for (int j = 0; i - j - 1 >= 0 and i + j < s.size() and s[i-j-1] == s[i+j]; j++) res++;
        }
        return res;
    }
};
