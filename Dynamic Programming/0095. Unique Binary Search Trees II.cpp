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
static vector<vector<TreeNode*>> F;
class Solution {
public:
    TreeNode* copy(TreeNode* root, int delta = 0)
    {
        if (!root) return nullptr;
        TreeNode* result = new TreeNode(root->val + delta);
        result->left = copy(root->left, delta);
        result->right = copy(root->right, delta);
        return result;
    }
    vector<TreeNode*> generateTrees(int N) {
        if (F.empty())
        {
            F = vector<vector<TreeNode*>>(9);
            F[0] = { nullptr };
        }
        function<vector<TreeNode*>(int)> dfs = [&](int N) -> vector<TreeNode*>
            {
                vector<TreeNode*>& result = F[N];
                if (result.empty())
                {
                    for (int root_val = 1; root_val <= N; ++root_val)
                    {
                        vector<TreeNode*> left = dfs(root_val - 1);
                        vector<TreeNode*> right = dfs(N - root_val);
                        for(auto L : left)
                            for (auto R : right)
                            {
                                result.emplace_back(new TreeNode(root_val));
                                result.back()->left = copy(L);
                                result.back()->right = copy(R, root_val);
                            }

                    }
                }
                return result;
            };
        return dfs(N);
    }
};
