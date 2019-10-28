/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        Parents.clear();
        it = root;
        while(it && it->left)
        {
            Parents.push_back(it);
            it = it->left;
        }
    }
    
    /** @return the next smallest number */
    int next() {
        int result = it->val;
        if (it->right)
        {
            it = it->right;
            while(it && it->left)
            {
                Parents.push_back(it);
                it = it->left;
            }
        }
        else if (!Parents.empty())
        {
            it = Parents.back(); Parents.pop_back();
        }
        else
            it = nullptr;
        return result;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return it != nullptr;
    }
    
    vector<TreeNode*> Parents;
    TreeNode* it;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */