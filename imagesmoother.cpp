class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        vector<vector<int>> S(M.size(), vector<int>(M[0].size(), 0));
        for (int i = 0; i < M.size(); i++) {
            for (int j = 0; j < M[0].size(); j++) {
                int sum = 0;
                int count = 0;
                for (int k = i-1; k < i+2; k++) {
                    for (int l = j-1; l < j+2; l++) {
                        if (k >= 0 and k < M.size() and l >= 0 and l < M[0].size()) {
                            sum += M[k][l];
                            count++;
                        }
                    }
                }
                S[i][j] = (sum)/count;
            }
        }
        return S;
    }
    
    
};
