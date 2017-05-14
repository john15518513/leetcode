class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        list<int> dp;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            if (!dp.empty() and dp.front() <= i-k) dp.pop_front();
            while (!dp.empty() and nums[i] > nums[dp.back()]) {
                dp.pop_back();
            }
            dp.push_back(i);
            if (i >= k-1) res.push_back(nums[dp.front()]);
        }
        return res;
    }
};
