class Solution {
public:
    int lengthOfLastWord(string s) {
        if (s.size() == 0) return 0;
        int end = s.size()-1;
        while (end >= 0 and s[end] == ' ') {
            end--;
        }
        if (end < 0) return 0;
        int start = end;
        while (start >= 0 and s[start] != ' ') {
            start--;
        }
        start += 1;
        return end-start+1;
    }
};
