class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxSum = 0;
        int curMax = 0;
        //cout << curMax <<endl;
        for(int i = 1; i < prices.size(); i++){
            curMax = max(0, curMax+prices[i]-prices[i-1]);
            maxSum = max(curMax, maxSum);
        }
        return maxSum;
    }
};
