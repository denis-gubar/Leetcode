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
class Solution {
public:
    unique_ptr<int[]> sum;
    void calcLevel(TreeNode* root, int level = 0)
    {
        if (!root) return;
        sum[level] += root->val;
        calcLevel(root->left, level + 1);
        calcLevel(root->right, level + 1);
    }
    void calc(TreeNode* root, int level = 0)
    {
        if (!root) return;
        if (level < 2)
            root->val = 0;
        int L = 0, R = 0;
        if (root->left)
        {
            if (root->left->left)
                L += root->left->left->val;
            if (root->left->right)
                L += root->left->right->val;
        }
        if (root->right)
        {
            if (root->right->left)
                R += root->right->left->val;
            if (root->right->right)
                R += root->right->right->val;
        }
        if (root->left)
        {
            if (root->left->left)
                root->left->left->val = sum[level + 2] - L;
            if (root->left->right)
                root->left->right->val = sum[level + 2] - L;
        }
        if (root->right)
        {
            if (root->right->left)
                root->right->left->val = sum[level + 2] - R;
            if (root->right->right)
                root->right->right->val = sum[level + 2] - R;
        }
        calc(root->left, level + 1);
        calc(root->right, level + 1);
    }
    TreeNode* replaceValueInTree(TreeNode* root) {
        sum = make_unique<int[]>(100'000);  
        calcLevel(root);
        calc(root);
        return root;
    }
};

