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
        dfs(root, s);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.size() == 0) return NULL;
        queue<int> que;
        stringstream ss(data);
        string tmp;
        while (getline(ss, tmp, ',')) {
            que.push(stoi(tmp));
        }
        return getNode(que);
    }
    void dfs(TreeNode* root, string &s) {
        if (!root) {
            return;
        }
        s = s + to_string(root->val);
        s.push_back(',');
        dfs(root->left, s);
        dfs(root->right, s);
    }
    TreeNode* getNode(queue<int> que) {
        if(que.empty()) return NULL;
        queue<int> smallerQue;
        TreeNode* root = new TreeNode(que.front());
        que.pop();
        while (que.size() && que.front() < root->val) {
            smallerQue.push(que.front());
            que.pop();
        }
        root->left = getNode(smallerQue);
        root->right = getNode(que);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
