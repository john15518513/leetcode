class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(nums, 0, nums.size());
        return res;
        
    }
    void dfs(vector<int> nums, int i, int j) {
        if (i == j) {
            res.push_back(nums);
            return;
        }
        for (int k = i; k < j; k++) {
            if (i!=k && nums[i] == nums[k]) continue;
            swap(nums[i], nums[k]);
            dfs(nums, i+1, j);
            //swap(nums[i], nums[k]);
        }
    }
private:
    vector<vector<int>> res;
};
