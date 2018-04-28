class Solution {
public:
    int characterReplacement(string s, int k) {
        int len = s.size();
        vector<int> count(26, 0);
        int start = 0, curMax = 0, maxLen = 0;
        for (int end = 0; end < len; end++) {
            curMax = max(curMax, ++count[s[end]-'A']);
            while (end-start+1-curMax > k) {
                count[s[start]-'A']--;
                //cout << start << " ";
                start++;
                
            }
            maxLen = max(maxLen, end-start+1);
        }
        return maxLen;
    }
};
