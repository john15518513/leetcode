class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.empty()) return vector<string>{};
        vector<string> res;
        int left = 0, right = 0;
        for (int i = 0; i < nums.size()-1; i++) {
            if (nums[i+1] - nums[i] == 1) right = i+1;
            else {
                if (left == right) res.push_back(to_string(nums[left]));
                else res.push_back(to_string(nums[left]) + "->" + to_string(nums[right]));
                left = i+1;
                right = i+1;
            }
        }
        if (left == right) res.push_back(to_string(nums[left]));
        else res.push_back(to_string(nums[left]) + "->" + to_string(nums[right]));
        return res;
    }
};
