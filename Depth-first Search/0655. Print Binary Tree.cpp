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
    int calcHeight(TreeNode* root)
    {
        if (!root) return 0;
        return 1 + max(calcHeight(root->left), calcHeight(root->right));
    }
    void print(vector<vector<string>>& result, TreeNode* root, int row, int col, int step)
    {
        if (!root) return;
        result[row][col] = to_string(root->val);
        step >>= 1;
        print(result, root->left, row + 1, col - step, step);
        print(result, root->right, row + 1, col + step, step);
    }
    vector<vector<string>> printTree(TreeNode* root) {
        int N = calcHeight(root);
        vector<vector<string>> result(N, vector<string>((1 << N) - 1));
        print(result, root, 0, (1 << (N - 1)) - 1, (1 << (N - 1)));
        return result;
    }
};
