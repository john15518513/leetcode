class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        if (s.size() < t.size()) swap(s, t);
        if (s.size()-t.size() > 1) return false;
        for (int i = 0; i < t.size(); i++) {
            if (s[i] != t[i]) {
                if (s.size() == t.size()) return s.substr(i+1) == t.substr(i+1);
                else {
                    return s.substr(i+1) == t.substr(i);
                }
            }
        }
        return s.size()-1 == t.size();   
    }
};
