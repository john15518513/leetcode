class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> res;
        int n = s.length();
        for (int i = 0; i < n-1; i++) {
            if (s[i] == s[i+1]) {
                if (s[i] == '+') {
                    res.push_back(s.substr(0,i)+"--"+s.substr(i+2, n-i-2));
                }
            }
        }
        return res;
    }
};
