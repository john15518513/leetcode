class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        string res = strs[0];
        for(int i = 1; i < strs.size(); i++) {
            int index = 0;
            while(index < min(res.length(), strs[i].length()) and res[index] == strs[i][index]) index++;
            res = res.substr(0, index);
        }
        return res;
    }
};
