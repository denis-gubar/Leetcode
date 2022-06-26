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
TreeNode* calc(TreeNode* root)
{
    TreeNode* result = nullptr;
    if (root)
    {
        result = new TreeNode(0);
        result->left = calc(root->left);
        result->right = calc(root->right);
    }
    return result;
}
class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<vector<TreeNode*>> results(n + 1);
        results[1].push_back(new TreeNode(0));
        for (int i = 3; i <= n; i += 2)
            for (int left = 1; left + 2 <= i; left += 2)
            {
                int right = i - left - 1;
                for(TreeNode* L : results[left])
                    for (TreeNode* R : results[right])
                    {
                        results[i].push_back(new TreeNode(0));
                        results[i].back()->left = calc(L);
                        results[i].back()->right = calc(R);
                    }
            }
        return results[n];
    }
    
};
