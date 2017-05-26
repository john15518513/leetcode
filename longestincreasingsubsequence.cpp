class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        /*if (nums.empty()) return 0;
        vector<int> dp(nums.size(), 1);
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i+1; j < nums.size(); j++) {
                if (nums[i] < nums[j])
                    dp[j] = max(dp[j], dp[i]+1);
            }
        }
        int maxV = dp[0];
        for (auto &d: dp) maxV = max(maxV, d);
        return maxV;*/
        vector<int> res;
        for(int i=0; i<nums.size(); i++) {
            auto it = std::lower_bound(res.begin(), res.end(), nums[i]);
            if(it==res.end()) res.push_back(nums[i]);
            else *it = nums[i];
            for(auto &c: res) cout << c << " ";
            cout << endl;
        }
        
        return res.size();
    }
};
