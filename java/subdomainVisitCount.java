class Solution {
    public List<String> subdomainVisits(String[] cpdomains) {
        Map<String, Integer> map = new HashMap<>();
        for (String s : cpdomains) {
            String[] splitStr = s.split("\\s+");
            String[] frags = splitStr[1].split("\\.");
            Integer times = Integer.valueOf(splitStr[0]);
            String cur = "";
            for (int i = frags.length - 1; i >= 0; --i) {
                cur = frags[i] + (i < frags.length - 1 ? "." : "") + cur;
                map.put(cur, map.getOrDefault(cur, 0) + times.intValue());
            }
        }
        
        List<String> result = new ArrayList<>();
        map.forEach((k, v) -> {
            result.add(v.toString() + " " + k);
        });
        
        return result;
    }
}
