class Solution {
public:
    void sortColors(vector<int>& nums) {
        int j = 0, k = 0;
        for (int i = 0; i < nums.size(); i++) {
            int v = nums[i];
            nums[i] = 2;
            if (v < 2) {
                nums[k] = 1;
                k++;
            }
            if (v == 0) {
                nums[j] = 0;
                j++;
            }
        }
    }
};
