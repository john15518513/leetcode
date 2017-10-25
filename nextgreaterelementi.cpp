class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        unordered_map<int, int> map;
        stack<int> s;
        for (auto &n : nums) {
            while (!s.empty() and n > s.top()) {
                map[s.top()] = n;
                s.pop();
            }
            s.push(n);
        }
        vector<int> res;
        for (auto &n: findNums) {
            if (map.find(n) == map.end()) res.push_back(-1);
            else res.push_back(map[n]);
        }
        return res;
    }
};
