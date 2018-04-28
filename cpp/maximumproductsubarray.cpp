class Solution {
public:
    int maxProduct(vector<int>& nums) {
        unsigned int n = nums.size(); 
        if (n == 0) {
            return 0;
        }
        vector<int> f(n, 0);
        vector<int> g(n, 0);
        f[0] = nums[0];
        g[0] = nums[0];
        int res = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            f[i] = max(max(f[i-1]*nums[i], g[i-1]*nums[i]), nums[i]);
            g[i] = min(min(g[i-1]*nums[i], f[i-1]*nums[i]), nums[i]);
            res = max(res, f[i]);
        }
        return res;
    }
};
