class Solution {
    private int index, maxLen;
    public String longestPalindrome(String s) {
        int len = s.length();
	    if (len < 2)
		    return s;
        for (int i = 0; i < s.length() - 1; i++) {
            LPS(s, i, i);
            LPS(s, i, i + 1);
        }
        return s.substring(index, index + maxLen);
    }
    
    private void LPS(String s, int i, int j) {
        while (i >= 0 && j < s.length() && s.charAt(i) == s.charAt(j)) {
            i--;
            j++;
        }
        
        if (maxLen < j - i - 1) {
            maxLen = j - i - 1;
            index = i + 1;
        }
    }
}
