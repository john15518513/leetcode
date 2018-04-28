class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        for (int i = 1; i < 10; i++) {
            if (i<=n) {
                helper(res, i, n);
            }
        }
        return res;
        
    }
    
    void helper (vector<int> &res, int i, int n) {
        res.push_back(i);
        for (int j = 0; j < 10; j++){
            if (i*10+j <= n) helper(res, i*10+j, n);
            else return;
        }
    }
    
};
