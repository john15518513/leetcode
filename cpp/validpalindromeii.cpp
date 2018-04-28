class Solution {
public:
    bool validPalindrome(string s) {
        int i = 0, j = s.size()-1;
        while (i < j) {
            if (s[i] != s[j]) break;
            i++;
            j--;
        }
        if (i >= j) return true;
        return isPalindrome(s, i+1, j) or isPalindrome(s, i, j-1);
    }
    bool isPalindrome(string s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};
