class Solution {
    public int[][] flipAndInvertImage(int[][] A) {
        for (int [] r : A) {
            for (int i = 0; i * 2 < r.length; i++) {
                if (r[i] == r[r.length - 1 - i]) r[i] = r[r.length - 1 - i] ^= 1;
            }
        }
        return A;
    }
}
