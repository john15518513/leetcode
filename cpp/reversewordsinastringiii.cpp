class Solution {
public:
    string reverseWords(string s) {
       int index = 0;
       for (int i = 0; i < s.length(); i++) {
           if (s[i] == ' ') index = i + 1;
           if (i+1 == s.length() or s[i+1] == ' ') {
               reverseWord(s, index, i);
               index = i+1;
           }
       }
       return s;
    }
    void reverseWord(string &s, int i, int j) {
        while (i < j) {
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }
};
