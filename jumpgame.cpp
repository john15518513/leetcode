class Solution {
public:
    bool canJump(vector<int>& nums) {
        int index = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (index < i) return false;
            index = max(index, i+nums[i]);
        }
        return index >= nums.size()-1;
    }
};
