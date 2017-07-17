class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0;
        for (int i = 0; i < k; i++) sum += nums[i];
        double maxNum = sum;
        for (int i = k; i < nums.size(); i++)  {
            sum += nums[i] - nums[i-k];
            maxNum = max(maxNum, sum);
        }
        return maxNum/float(k);
    }
};
