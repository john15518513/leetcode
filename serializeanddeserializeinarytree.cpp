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
        string s = "";
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            int num = que.size();
            for (int i = 0; i < num; i++) {
                auto target = que.front();
                que.pop();
                if (target) {
                    que.push(target->left);
                    que.push(target->right);
                    s += (to_string(target->val) + ",");
                }
                else {
                    s += "#,";
                }
            }
        }
        cout << s << endl;
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.length() == 2 and data == "#,") return NULL;
        int pos = data.find(",");
        int val = stoi(data.substr(0, pos));
        data = data.substr(pos+1);
        TreeNode* root = new TreeNode(val);
        queue<TreeNode*> que;
        que.push(root);
        while (que.size()) {
            auto target = que.front();
            que.pop();
            pos = data.find(",");
            if (data.substr(0, pos) != "#") { 
                val = stoi(data.substr(0, pos));
                target->left = new TreeNode(val);
                que.push(target->left);
                
            }
            data = data.substr(pos+1);
            pos = data.find(",");
            if (data.substr(0, pos) != "#") { 
                val = stoi(data.substr(0, pos));
                target->right = new TreeNode(val);
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
