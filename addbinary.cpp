class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;
        int c = 0;
        string s = "";
        while (i >= 0 or j >= 0 or c >= 1) {
            c += i >= 0 ? a[i--] - '0' : 0;
            c += j >= 0 ? b[j--] - '0' : 0;
            s = to_string(c%2) + s;
            c /= 2;
        }
        return s;
    }
};
