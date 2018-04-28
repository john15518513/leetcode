class Solution {
public:
    int nextGreaterElement(int n) {
        auto digits = to_string(n);
        next_permutation(digits.begin(), digits.end());
        auto res = stoll(digits);
        return (res > INT_MAX || res <= n) ? -1 : res;
    }
};
