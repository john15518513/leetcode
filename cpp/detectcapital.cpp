class Solution {
public:
    bool detectCapitalUse(string word) {
        int cnt = 0;
        for (int i = 0; i < word.length(); i++) {
            if (cnt > 1 and islower(word[i])) return false;
            if (isupper(word[i])) {
                cnt++;
            }
            
        }
        return cnt == word.length() || cnt == 0 || cnt == 1 && isupper(word[0]);
    }
};
