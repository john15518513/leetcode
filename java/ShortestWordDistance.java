class Solution {
    public int shortestDistance(String[] words, String word1, String word2) {
        int w1Index = -1;
        int w2Index = -1;
        int shortestDistance = Integer.MAX_VALUE;
        
        for (int i = 0; i < words.length; i++) {
            if (words[i].equals(word1)) {
                w1Index = i;
            }
            if (words[i].equals(word2)) {
                w2Index = i;
            }
            if (w1Index != -1 && w2Index != -1) {
                shortestDistance = Math.min(Math.abs(w1Index - w2Index), shortestDistance);
            }
        }
        
        return shortestDistance;
    }
}
