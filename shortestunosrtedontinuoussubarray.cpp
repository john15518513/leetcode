class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int left = -1, right = -1;
        for (int i = 0; i < nums.size(); i++) {
            int flag = false;
            for (int j = i+1; j < nums.size(); j++) {
                if (nums[i] > nums[j]) {
                    flag = true;
                    left = i;
                    break;
                }
            }
            if (flag) break;
        }
        if (left == -1) return 0;
        for (int i = nums.size()-1; i >= 0; i--) {
            int flag = false;
            for (int j = i-1; j >= 0; j--) {
                if (nums[i] < nums[j]) {
                    flag = true;
                    right = i;
                    break;
                }
            }
            if (flag) break;
        }
        return right-left+1;
    }
};
