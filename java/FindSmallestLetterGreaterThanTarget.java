class Solution {
    public char nextGreatestLetter(char[] letters, char target) {
        int n = letters.length;
        int lo = 0, hi = n;
        
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (target >= letters[mid]) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return letters[lo % n];
    }
}
