class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int maxV = INT_MIN;
        vector<bool> visited(nums.size(), false);
        for (int i = 0; i < nums.size(); i++) {
        	if (visited[i]) 
        		continue;
        	maxV = max(maxV, calcLength(nums, i, visited));
        }
        return maxV;
    }
    int calcLength(vector<int> &nums, int start, vector<bool> &visited) {
		int i = start, count = 0;
		while (count == 0 || i != start) {
			visited[i] = true;
			i = nums[i];
			count++;
		}
		return count;
	}
};
