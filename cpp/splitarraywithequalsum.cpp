
class Solution {
public:
    bool splitArray(vector<int>& nums) {
        if (nums.size() < 7) return false;
        vector<int> sum(nums.size(), nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            sum[i] = sum[i-1] + nums[i];
        }
        for (int i = 3; i < nums.size()-3; i++) {
            unordered_set<int> set;
            //cut the first half
            for (int j = 1; j < i-1; j++) {
                if (sum[j-1] == sum[i-1] - sum[j]) set.insert(sum[j-1]);
            }
            //cut the second half
            for (int j = i+2; j < nums.size()-1; j++) {
                if (sum[j-1] - sum[i] == sum.back() - sum[j] and set.find(sum[j-1] - sum[i]) != set.end()) return true;
            }
        }
        return false;
    }
};
