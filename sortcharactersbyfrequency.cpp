class Solution {
public:
    string frequencySort(string s) {
        for (auto &c: s) count[c]++;
        sort(s.begin(), s.end(), [&](const char &a, const char &b){return count[a] > count[b] || (count[a] == count[b] && a < b);});
        return s;
    }
private:
    unordered_map<char, int> count;
};
