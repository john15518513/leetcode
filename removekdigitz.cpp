class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> s;
        for (auto &c : num) {
            while (k > 0 and !s.empty() and c < s.top()) {
                s.pop();
                k--;
            }
            s.push(c);
        }
        while (k > 0 and !s.empty()) {
            s.pop();
            k--;
        }
        //if (s.empty()) return "0";
        string res = "";
        while (!s.empty()) {
            res.push_back(s.top());
            s.pop();
        }
        while (res.back() == '0') res.pop_back();
        if (res.size() == 0) return "0";
        return string(res.rbegin(), res.rend());
    }
};
