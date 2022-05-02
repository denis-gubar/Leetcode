/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
    void calc(TreeNode* root)
    {
        if (!root) return;
        calc(root->left);
        data.push_back(root);
        calc(root->right);
    }

    BSTIterator(TreeNode* root) {
        data.push_back(new TreeNode(-1));
        calc(root);
        data.push_back(new TreeNode(-1));
        it = data.begin();
    }
    
    bool hasNext() {
		auto result = *(it + 1);
		return result->val >= 0;
    }
    
    int next() {
        ++it;
        return (*it)->val;
    }
    
    bool hasPrev() {
        if (it == data.begin())
            return false;
		auto result = *(it - 1);
		return result->val >= 0;
    }
    
    int prev() {
        --it;
        return (*it)->val;
    }
    vector<TreeNode*> data;
    vector<TreeNode*>::iterator it;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * bool param_1 = obj->hasNext();
 * int param_2 = obj->next();
 * bool param_3 = obj->hasPrev();
 * int param_4 = obj->prev();
 */
