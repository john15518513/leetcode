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
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> tmp;
        dfs(s, tmp);
        return res;
    }
    void dfs(string s, vector<string> &tmp) {
        if (s.empty()) {
            res.push_back(tmp);
        }
        for (int i = 0; i < s.size(); i++) {
            if (isPalindrome(s.substr(0, i+1))) {
                tmp.push_back(s.substr(0, i+1));
                dfs(s.substr(i+1), tmp);
                tmp.pop_back();
            }
        }
    }
    bool isPalindrome(string s) {
        int i = 0, j = s.size()-1;
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    
private:
    vector<vector<string>> res;
};
