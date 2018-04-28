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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root or root == p or root == q) return root;
        auto left = lowestCommonAncestor(root->left, p, q);
        auto right = lowestCommonAncestor(root->right, p, q);
        if (left and right) return root;
        else if (left and ! right) return left;
        else if (!left and right) return right; 
        return NULL;
    }
};

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        queue<TreeNode*> que;
        unordered_map<TreeNode*, TreeNode*> map;
        map[root] = NULL;
        que.push(root);
        while (!que.empty()) {
            auto target = que.front();
            que.pop();
            if (target->left) {
                map[target->left] = target;
                que.push(target->left);
            }
            if (target->right) {
                map[target->right] = target;
                que.push(target->right);
            }
        }
        unordered_set<TreeNode*> set;
        while (p != NULL) {
            set.insert(p);
            p = map[p];
        }
        while (q != NULL) {
            if (set.find(q) != set.end()) return q;
            q = map[q];
        }
    }
};
