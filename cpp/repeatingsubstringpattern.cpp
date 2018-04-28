class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int len = s.length()/2;
        for (int i = len-1; i >= 0; i--) {
            string token = s.substr(0,i+1);
            //cout << "token: "<< token << " ";
            int pos = i+1;
            //cout << "len: " << i+1 << "pos: " << pos << endl;
            while (true) {
                if (pos == s.length()) return true;
                if (pos+i+1 > s.length()) break;
                if (token != s.substr(pos, i+1))break;
                pos += i+1;
            }
        }
        return false;
    }
};

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        /*int len = s.length()/2;
        for (int i = len-1; i >= 0; i--) {
            string token = s.substr(0,i+1);
            int pos = i+1;
            while (true) {
                if (pos == s.length()) return true;
                if (pos+i+1 > s.length()) break;
                if (token != s.substr(pos, i+1))break;
                pos += i+1;
            }
        }
        return false;*/
        string ss = s + s;
        //cout << ss.find(s, 1)  << " "  << s.length() << endl;
        return ss.find(s, 1) < s.size();
    }
};
