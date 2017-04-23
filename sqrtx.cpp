class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 or x == 1) return x;
        int i =  1, j = x;
        while (1) {
            int mid = i + (j-i)/2;
            if (pow(mid, 2) <= x and pow(mid+1, 2) > x) return mid;
            else if (pow(mid, 2) < x) {
                i = mid + 1;
            }
            else {
                j = mid - 1;
            }
        }
    }
};
