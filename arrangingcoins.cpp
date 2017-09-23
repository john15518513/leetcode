class Solution {
public:
    int arrangeCoins(int n) {
        int i = 1;
        int count = 0;
        while (n >= 0) {
            if (n-i >= 0) count++;
            n -= i;
            i++;
        }
        return count;
    }
};
