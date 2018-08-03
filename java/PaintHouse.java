class Solution {
    public int minCost(int[][] costs) {
        
        if(costs == null || costs.length == 0){
            return 0;
        }
        
        for (int i = 1; i < costs.length; i++) {
            for (int j = 0; j < 3; j++) {
                costs[i][j] += Math.min(costs[i-1][(j+1)%3], costs[i-1][(j+2)%3]);
            }
        }
        
        int n = costs.length-1;
        return Math.min(Math.min(costs[n][0], costs[n][1]), costs[n][2]);
    }
}
