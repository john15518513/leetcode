class Solution {
public:
    bool hasAlternatingBits(int n) {
        int c = n%2;
        n >>= 1;
        while(n) {
            if (c^(n%2) == 0) return false;
            c = n%2;
            n >>= 1;
        }
        return true;
    }
};
