class Solution {
public:
    struct TreeNode {
        char val;
        TreeNode* left;
        TreeNode* right;
    };
    TreeNode* calc(string& expression, int& pos)
    {
        TreeNode* root = new TreeNode{ expression[pos], nullptr, nullptr };
        ++pos;
        if (pos != expression.size())
        {
            if (expression[pos] == '?')
            {
                ++pos;
                root->left = calc(expression, pos);
                ++pos;
                root->right = calc(expression, pos);
            }
        }
        return root;
    }
    string parseTernary(string expression) {
        int pos = 0;
        TreeNode* root = calc(expression, pos);
        while (root->left)
            root = root->val == 'T' ? root->left : root->right;
        return string(1, root->val);
    }
};
