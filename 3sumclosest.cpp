class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int minVal = INT_MAX;
        int minGap = INT_MAX;
        sort(nums.begin(), nums.end(), [](const int &i, const int &j){return i<j;});
        for (int i = 0; i < nums.size()-2; i++) {
            int j = i+1, k = nums.size()-1;
            while (j < k) {
                int tmp = nums[i] + nums[j] + nums[k];
                if (tmp == target) return target;
                if (abs(tmp-target) < minGap) {
                    minGap = abs(tmp-target);
                    minVal = tmp;
                }
                if (tmp < target) j++;
                else k--;
            }
        }
        return minVal;
        
    }
};
