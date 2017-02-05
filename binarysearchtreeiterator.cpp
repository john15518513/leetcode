/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    stack<TreeNode *> myStack;
    BSTIterator(TreeNode *root) {
        push(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        //cout << myStack.size() << endl;
        return !myStack.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *ptr = myStack.top();
        
        myStack.pop();
        push(ptr->right);
        return ptr->val;
    }
private:
    void push(TreeNode *root){
        while(root!=NULL){
            myStack.push(root);
            root = root->left;
        }
    }
    
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
