class Solution {
    public String[] findRestaurant(String[] list1, String[] list2) {
        Map<String, Integer> map = new HashMap<String, Integer>();
        List<String> result = new ArrayList<String>();
        int count = Integer.MAX_VALUE;
        for (int i = 0; i < list1.length; i++) {
            map.put(list1[i], i);
        }
        for (int i = 0; i < list2.length; i++) {
            if (map.containsKey(list2[i]) && map.get(list2[i]) + i < count) {
                count = map.get(list2[i]) + i;
                result = new ArrayList<String>(Arrays.asList(list2[i]));
            } else if (!map.containsKey(list2[i]) || (map.containsKey(list2[i]) && map.get(list2[i]) + i > count)) {
                continue;
            } else {
                result.add(list2[i]);
            }
        }
        String[] arr = new String[result.size()];
        return result.toArray(arr);
    }
}
