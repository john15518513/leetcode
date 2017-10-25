class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;
        int index = 0;
        int product = 1;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            product *= nums[i];
            while (product >= k) {
                product /= nums[index++];
            }
            count += i-index+1;
        }
        return count;
    }
};
