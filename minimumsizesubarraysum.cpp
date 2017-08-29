class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int sum = 0;
        int left = 0, right = -1;
        int minLen = INT_MAX;
        while(right < int(nums.size()) and left < nums.size()) {
            if (sum < s) {
                right++;
                sum += nums[right];
            }
            else {
                minLen = min(minLen, right-left+1);
                sum -= nums[left];
                left++;
            }
            //cout << left << " " << right << endl;
        }
        return minLen == INT_MAX? 0 : minLen;
    }
};
