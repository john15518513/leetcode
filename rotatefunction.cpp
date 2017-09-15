class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int sum = 0;
        int len = A.size();
        int F = 0;
        for (int i = 0; i < len; i++) {
            F += i*A[i];
            sum += A[i];
        }
        int maxV = F;
        for (int i = len - 1; i >= 1; i--) {
            F = F + sum - len * A[i];
            maxV = max(F, maxV);
        }
        return maxV; 
    }
};
