// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int i = 1, j = n;
        int mid;
        while (i <= j) {
            mid = i + (j-i)/2;
            int hint = guess(mid);
            if (!hint) return mid;
            if (hint == -1) j = mid-1;
            else i = mid+1;
        }
    }
};
