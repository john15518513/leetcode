class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), cmp);
        int cnt = 0;
        for(int i = 0, j = 0; j < apairs.size(); j++) {
            if (j == 0 || pairs[i][1] < pairs[j][0]) {
                cnt++;
                i = j;
            }
        }
        return cnt;
    }
    static bool cmp(vector<int>& a, vector<int>&b) {
        return a[1] < b[1];
    }
};

//DP Solution
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), cmp);
        int maxV = 1;
        vector<int> dp(pairs.size(), 1);
        for (int i = 1; i < pairs.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (pairs[i][0] > pairs[j][1]) {
                    dp[i] = max(dp[i], dp[j]+1);  
                }
            }
            maxV = max(maxV, dp[i]);
        }
        return maxV;
        
    }
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[0] < b[0];
    }
};
