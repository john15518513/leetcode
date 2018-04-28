class Solution {
public:
    bool canWin(string s) {
        if (s == "" or s.size() <2) return false;
        for (int i = 0; i < s.size()-1; i++) {
            if (s.substr(i,2) == "++") {
                string t = s.substr(0, i) + "--" + s.substr(i+2);
                if (!canWin(t)) return true;
            }
        }
        return false;
    }
};
