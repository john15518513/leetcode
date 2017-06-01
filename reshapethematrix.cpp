class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int nr = nums.size(), nc = nums[0].size();
        if (nr*nc != r*c) return nums;
        vector<vector<int>> res(r, vector<int>(c, 0));
        for (int i = 0; i < nr; i++) {
            for (int j = 0; j < nc; j++) {
                res[(i*nc+j)/c][(i*nc+j)%c] = nums[i][j];
            }
        }
        return res;
    }
};
