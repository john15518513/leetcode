class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i = 0, j = nums.size()-1;
        int mid;
        while (i < j) {
            mid = i + (j-i)/2;
            if (nums[mid] <= nums[j]) j = mid;
            else i = mid + 1;
        }
        int k = i;
        i = 0;
        j = nums.size()-1;
        int n = nums.size();
        while (i <= j) {
            mid = i + (j-i)/2;
            if (nums[(mid+k)%n] == target) return (mid+k)%n;
            else if (nums[(mid+k)%n] < target) i = mid + 1;
            else j = mid - 1;
        }
        return -1;
    }
};
