class Solution {
public:
    bool judgeSquareSum(int c) {
        int left = 0, right = sqrt(c);
        while (left <= right) {
            int cur = pow(left,2) + pow(right, 2);
            if (cur < c) left++;
            else if (cur > c) right--;
            else return true;
        }
        return false;
    }
};
