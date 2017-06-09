class Solution {
public:
    bool checkRecord(string s) {
        int a = 0, ll = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'A') a++;
            if (i > 1 and s[i] == 'L' and s[i-1] == 'L' and s[i-2] == 'L') ll++;
        }
        return a <= 1 and !ll ;
    }
};
