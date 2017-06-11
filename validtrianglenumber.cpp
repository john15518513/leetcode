class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        if (nums.size() < 3) return 0;
        sort(nums.begin(), nums.end());
        int count = 0;
        for (int i = nums.size()-1; i >= 2; i--) {
            int j = 0, k = i-1;
            while (j < k) {
                if (nums[j] + nums[k] <= nums[i]) j++;
                else {
                    count += k-j;
                    k--;
                }
            }
        }
        return count;
    }
};
