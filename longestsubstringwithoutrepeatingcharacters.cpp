class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> table;
        int maxLen = 0;
        int start = 0;
        for (int i = 0; i < s.length(); i++) {
            if (table.find(s[i]) != table.end() and start <= table[s[i]]) start = table[s[i]] + 1;
            table[s[i]] = i;
            maxLen = max(maxLen, i-start+1);
        }
        return maxLen;
    }
};
