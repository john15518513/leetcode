class Solution {
public:
    void reverseWords(string &s) {
        reverse(s.begin(), s.end());
        int index = 0;
        int i;
        for (i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                reverse(s.begin()+index, s.begin()+i);
                index = i+1;
            }
        }
        reverse(s.begin()+index, s.begin()+i);
    }
};
