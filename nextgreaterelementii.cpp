class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> s;
        vector<int> res(n, -1);
        for (int i = 0; i < n*2; i++) {
            int num = nums[i%n];
            while (!s.empty() and num > nums[s.top()]) {
                res[s.top()] = num;
                s.pop();
            }
            if (i < n) s.push(i);
        }
        return res;
    }
};
