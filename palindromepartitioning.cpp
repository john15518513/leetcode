class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> tmp;
        for (int i = 0; i < s.length(); i++) {
            dfs(s.substr(0, i+1), tmp, 0, s.length());
        }
        return res;
    }
    void dfs(string s, vector<string> &tmp, int len, int total) {
        if (len == total) {
            res.push_back(tmp);
        }
        for (int i = 0; i < s.length(); i++) {
            string ss = s.substr(0,i+1);
            string rs = s.substr(0,i+1);
            reverse(rs.begin(), rs.end());
            if (ss == rs) {
                tmp.push_back(ss);
                dfs(s.substr(ss.length(), s.length()-ss.length()), tmp, len+i+1, total);
                tmp.pop_back();
            }
        }
    }
    
private:
    vector<vector<string>> res;
};

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> tmp;
        dfs(s, tmp, 0, s.length());
        return res;
    }
    void dfs(string s, vector<string> &tmp, int len, int total) {
        if (len == total) {
            res.push_back(tmp);
        }
        for (int i = 0; i < s.length(); i++) {
            string ss = s.substr(0,i+1);
            string rs = s.substr(0,i+1);
            reverse(rs.begin(), rs.end());
            if (ss == rs) {
                tmp.push_back(ss);
                dfs(s.substr(ss.length()), tmp, len+i+1, total);
                tmp.pop_back();
            }
        }
    }
    
private:
    vector<vector<string>> res;
};
