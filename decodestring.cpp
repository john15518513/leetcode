class Solution {
public:
    string decodeString(string s) {
        int i = 0;
        return decodeString(s, i);
    }
    string decodeString(string& s, int& i) {
        string res = "";
        while (i < s.size() && s[i] != ']') {
            if (!isdigit(s[i]))
                res += s[i++];
            else {
                int cur = 0;
                while (i < s.length() and isdigit(s[i])) {
                    cur = cur*10 + s[i++]-'0';
                }
                i++;
                string tmp = decodeString(s, i);
                i++;
                for (int j = 0; j < cur; j++) res += tmp;
            }
        }
        return res;
    }
};
