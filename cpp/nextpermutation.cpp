class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i;
        for (i = nums.size()-1; i > 0; i--) {
            if (nums[i] > nums[i-1]) break;    
        }
        if (!i) {
            reverse(nums.begin(), nums.end()); 
            return;
        }
        for (int j = nums.size()-1; j >= i; j--) {
            if (nums[j] > nums[i-1]) {
                swap(nums[j], nums[i-1]);
                break;
            }
        }
        sort(nums.begin()+i, nums.end());
    }
};
