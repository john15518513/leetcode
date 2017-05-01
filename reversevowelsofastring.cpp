class Solution {
public:
    string reverseVowels(string s) {
        set<char> table({'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'});
        int i = 0, j = s.length()-1;
        while(i < j) {
            i = s.find_first_of("aeiouAEIOU", i);
            j = s.find_last_of("aeiouAEIOU", j);
            if (i < j) {
                swap(s[i++], s[j--]);
            }
        }
        return s;
    }
};
