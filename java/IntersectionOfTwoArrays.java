class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        Set<Integer> set1 = new HashSet<>();
        Set<Integer> set2 = new HashSet<>();
        for (int n : nums1) set1.add(n);
        for (int n : nums2) {
            if (set1.contains(n)) set2.add(n);
        }
        
        return set2.stream().mapToInt(Number::intValue).toArray(); // Java 8
    }
}
