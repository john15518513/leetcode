class Solution {
    public int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 2;
        }
        
        int n1 = 1;
        int n2 = 2;
        int res;
        for (int i = 3; i <= n; i++) {
            res = n1 + n2;
            n1 = n2;
            n2 = res;
        }
        
        return res;
    }
}
