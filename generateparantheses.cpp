class Solution {
public:
    vector<string> generateParenthesis(int n) {
        dfs("", n, n);
        return res;
    }
    void dfs(string path, int left, int right) {
        if (left == 0 and right == 0) {
            res.push_back(path);
            return;
        }
        if (left > 0){
            dfs(path+"(", left-1, right);
        }
        if (right > left) {
            dfs(path+")", left, right-1);
        }
        
    }
private:
    vector<string> res;
};
