class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0 || (x != 0 and x%10 == 0)) return false;
        int num = 0;
        while (num < x) {
            num = num*10+x%10;
            x /= 10;
        }
        if (num == x or num/10 == x) return true;
        return false;
    }
};
