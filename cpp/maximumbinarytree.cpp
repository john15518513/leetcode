/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.size() == 0) return NULL;
        return build(nums, 0, nums.size()-1);
    }
    TreeNode* build(vector<int> &nums, int start, int end) {
        if (start > end) return NULL;
        int maxIndex = start;
        for (int i = start; i <= end; i++) {
            if (nums[i] > nums[maxIndex]) maxIndex = i;
        }
        TreeNode *root = new TreeNode(nums[maxIndex]);
        root -> left = build(nums, start, maxIndex-1);
        root -> right = build(nums, maxIndex+1, end);
        return root;
    }
};
