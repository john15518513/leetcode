class Solution {
public:
    bool checkValidString(string s) {
        return dfs(s, 0, 0);
    }
    bool dfs(string &s, int i, int count) {
        if (count < 0) return false;
        for (int j = i; j < s.size(); j++) {
            //cout << ":"<<j << endl;
            auto tmp = s[j];
            
            if (s[j] == '(') { 
                //cout << tmp << " " << s[j] << endl;
                count++;
            }
            
            if (s[j] == ')') {
                //cout << tmp << " " << s[j] << endl;
                if (count <= 0) return false;
                count--;
            }
            if (s[j] == '*'){
                return dfs(s, j+1, count-1) or dfs(s, j+1, count+1) or dfs(s, j+1, count);
            }
            //cout << count << endl;
        }
        //cout << count << endl;
        return count == 0;
    }
};
