class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        dfs(nums, 0);
        return res;
    }
    void dfs(vector<int> &nums, int index) {
        if (index == nums.size()) {
            res.push_back(nums);
            return;
        }
        for(int i = index; i < nums.size(); i++) {
            swap(nums[index], nums[i]);
            dfs(nums, index+1);
            swap(nums[index], nums[i]);
        }
    }
private:
    vector<vector<int>> res;
};
