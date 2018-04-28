class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> count;
        for (auto &c: s) {
            if (count.find(c) != count.end()) count[c] += 1;
            else count[c] = 1;
        }
        int oddCount = 0;
        for (auto &i: count) {
            if (i.second%2) oddCount++;
        }
        return oddCount < 2;
    }
};
