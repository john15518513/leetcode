class Solution {
    public String mostCommonWord(String paragraph, String[] banned) {
        String[] words = paragraph.toLowerCase().split("[\\s!?',;.]+");
        Set<String> set = new HashSet<String>(Arrays.asList(banned));
                
        Map<String, Integer> map = new HashMap<>();
        for (String word : words) {
            if (!set.contains(word)) {
                map.put(word, map.getOrDefault(word, 0) + 1);
            }
        }
        
        String res = "";
        Integer curMax = Integer.MIN_VALUE;
        return Collections.max(map.entrySet(), Map.Entry.comparingByValue()).getKey();
    }
}
