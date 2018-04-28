class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        //vector<vector<int>> dp(A.size()+1, vector<int>(B.size()+1, 0));
        int dp[A.size()+1][B.size()+1] = {};
        int maxV = 0;
        for (int i = 1; i < A.size()+1; i++) {
            for (int j = 1; j < B.size()+1; j++) {
                if (A[i-1] == B[j-1]) {
                    dp[i][j] = dp[i-1][j-1]+1;
                    maxV = max(maxV, dp[i][j]);
                }
            }
        }
        return maxV;
    }
};
