class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int minVal = dfs(price, special, needs);
        return minVal;
    }
    int dfs(vector<int>& price, vector<vector<int>>& special, vector<int> needs) {
        if (allZero(needs) == 0) return 0;
        if (allZero(needs) < 0) return INT_MAX;
        int minVal = 0;
        for (int i = 0; i < needs.size(); i++) {
            minVal += price[i]*needs[i];
        }
        for (auto &p: special) {
            vector<int> tmp = needs;
            for (int i = 0; i < p.size()-1; i++) {
                tmp[i] -= p[i];
            }
            int tmpV = dfs(price, special, tmp);
            minVal = min(minVal,  tmpV == INT_MAX? INT_MAX:tmpV+p.back());
        }
        return minVal;
    }
    int allZero(vector<int>& needs) {
        int sum = 0;
        for (auto &n: needs) {
            if (n < 0) return -1;
            sum += n;
        }
        return sum;
    }
};
