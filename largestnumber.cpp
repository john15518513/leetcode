class Solution {
    struct cmp{
        bool operator()(const int a, const int b) {
            auto as = to_string(a);
            auto bs = to_string(b);
            return as+bs > bs+as;
        }  
    };
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp());
        string res = "";
        for (auto &n: nums) {
            res = res + to_string(n);
        }
        while (res.size() > 1 and res.front() == '0') res.erase(res.begin());
        return res;
    }
};
