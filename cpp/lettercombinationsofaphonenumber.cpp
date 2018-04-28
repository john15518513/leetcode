class Solution {
public:
    Solution(): table({
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}}) {}
    
    vector<string> letterCombinations(string digits) {
        if (digits.length() == 0) return vector<string>();
        string path = "";
        dfs(digits, 0, path);
        return res;
    }
    void dfs(string &digits, int index, string &path) {
        if (index == digits.length()) {
            res.push_back(path);
            return;
        }
        for(int i = 0; i < table[digits[index]].length(); i++) {
            path += table[digits[index]][i];
            dfs(digits, index+1, path);
            path.erase(path.end()-1);
        }
    }
private:
    unordered_map<char, string> table;
    vector<string> res;
    
};
