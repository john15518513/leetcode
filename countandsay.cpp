class Solution {
public:
    string countAndSay(int n) {
        if (n == 0) return "";
        string res = "1";
        while (--n) {
            string tmp = res;
            res = "";
            int count = 1;
            char curWord = tmp[0];
            for (int i = 1; i < tmp.length(); i++) {
                if (curWord != tmp[i]) {
                    res += to_string(count) + curWord;
                    count = 1;
                    curWord = tmp[i];
                }
                else {
                    count++;
                }
            }
            res += to_string(count) + curWord;
        }
        return res;
    }
};
