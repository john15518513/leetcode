class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(nums.size(), 1);
        vector<int> fromBegin(n, 1);
        vector<int> fromEnd(n, 1);
        for (int i = 0; i < n; i++) {
            fromBegin[i] = nums[i] * (i-1 >= 0? fromBegin[i-1]:1);
            fromEnd[n-i-1] = nums[n-i-1] * (n-i < n? fromEnd[n-i]:1);
        }
        for (int i = 1; i < n-1; i++) {
            res[i] = fromBegin[i-1] * fromEnd[i+1];
        }
        res[0] = fromEnd[1];
        res.back() = fromBegin[n-2];
        return res;
    }
};
