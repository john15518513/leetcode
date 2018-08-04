class Solution {
    public int maxSubArray(int[] nums) {
        if (nums == null || nums.length == 0) {
            return 0;
        }
        int maxSub = Integer.MIN_VALUE;
        int curMax = 0;
        for (int i = 0; i < nums.length; i++) {
            curMax = (curMax + nums[i]) > nums[i] ? curMax + nums[i] : nums[i];
            maxSub = Math.max(maxSub, curMax);
        }
        return maxSub;
    }
}
