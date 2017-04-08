class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curSum = nums[0];
        int maxSum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            curSum = nums[i] + (curSum > 0 ? curSum : 0); 
            maxSum = max(maxSum, curSum);
        }
        return maxSum;
    }
};
