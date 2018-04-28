class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        int low = 0, high = preorder.size()-1;
        return dfs(preorder, low, high);
    }
    bool dfs(vector<int>& preorder, int low, int high) {
        if (low >= high) return true;
        int i = low+1, j;
        while (preorder[low] > preorder[i] and i <= high) i++;
        j = i;
        while (preorder[low] <= preorder[i] and i <= high) i++;
        if (i <= high) return false;
        return dfs(preorder, low+1, j-1) and dfs(preorder, j, high);
    }
};
