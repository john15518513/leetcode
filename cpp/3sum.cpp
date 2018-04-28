class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() < 3) return res;
        set<tuple<int, int, int>> pool;
        sort(nums.begin(), nums.end(), [](const int &i, const int &j){return i<j;});
        //cout << nums.size()-2 << endl;
        for (int i = 0; i < nums.size()-2; i++) {
            int j = i+1, k = nums.size()-1;
            while (j<k) {
                int tmp = nums[i] + nums[j] + nums[k];
                if (tmp == 0 and pool.find(make_tuple(nums[i], nums[j], nums[k])) == pool.end()) {
                    res.push_back({nums[i], nums[j], nums[k]});
                    pool.insert(make_tuple(nums[i], nums[j], nums[k]));
                }
                if (tmp < 0) {
                    j++;
                }
                else {
                    k--;
                }
            }
        }
        return res;
    }
};
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() < 3) return res;
        sort(nums.begin(), nums.end(), [](const int &i, const int &j){return i<j;});
        for (int i = 0; i < nums.size()-2; i++) {
            int j = i+1, k = nums.size()-1;
            if (i != 0 and nums[i] == nums[i-1]) continue;
            while (j<k) {
                int tmp = nums[i] + nums[j] + nums[k];
                if (tmp == 0) {
                    res.push_back({nums[i], nums[j], nums[k]});
                    while (j < k and nums[j] == nums[j+1]) j++;
                    while (j < k and nums[k] == nums[k-1]) k--;
                }
                if (tmp < 0) {
                    j++;
                }
                else {
                    k--;
                }
            }
        }
        return res;
    }
};
