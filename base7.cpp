class Solution {
public:
    string convertToBase7(int num) {
        string res = "";
        int n = abs(num);
        do {
            res = to_string(n%7)+res;
        } while(n/=7);
        return num<0? "-"+res:res;
    }
};
