class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        for (int i = 1; i < nums.size(); i++) {
            nums[i] += nums[i-1];
        }
        /*for (int i = 0; i < nums.size(); i++) {
            cout << nums[i] << " ";
        }*/
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = -1; j < i; j++) {
                if (j == -1 and nums[i] == k) count++;
                else if (nums[i] - nums[j] == k) count++;
            }
        }
        return count;
    }
};
