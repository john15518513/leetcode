/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = "";
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            auto target = que.front();
            que.pop();
            if (!target) {
                res += "N,";
            }
            else {
                res += to_string(target->val) + ",";
                que.push(target->left);
                que.push(target->right);
            }
        }
        return res;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.length() == 2 and data == "N,") {
            return NULL;
        }
        queue<TreeNode*> que;
        int pos = data.find(",");
        TreeNode* root = new TreeNode(stoi(data.substr(0, pos)));
        que.push(root);
        data = data.substr(pos+1);
        while (!que.empty()) {
            auto target = que.front();
            que.pop();
            pos = data.find(",");
            if (data.substr(0, pos) != "N") {
                target->left = new TreeNode(stoi(data.substr(0, pos)));
                que.push(target->left);
            }
            data = data.substr(pos+1);
            pos = data.find(",");
            if (data.substr(0, pos) != "N") {
                target->right = new TreeNode(stoi(data.substr(0, pos)));
                que.push(target->right);
            }
            data = data.substr(pos+1);
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
