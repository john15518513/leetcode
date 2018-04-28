class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map <string, vector<string>> dic;
        for (int i = 0; i<strs.size(); i++) {
            string sortedWord = strs[i];
            sort(sortedWord.begin(), sortedWord.end());
            dic[sortedWord].push_back(strs[i]);
        }
        vector<vector<string>> res;
        for (auto &x: dic) {
            vector<string> tmp(dic[x.first].begin(), dic[x.first].end());
            res.push_back(tmp);
        }
        return res;
    }
};
