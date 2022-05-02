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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> M;
        int N = descriptions.size();
        unordered_set<int> S;
        for (int i = 0; i < N; ++i)
        {
			int const& parent = descriptions[i][0];
			int const& child = descriptions[i][1];
			int const& isLeft = descriptions[i][2];
            if (M.find(parent) == M.end())
                M[parent] = new TreeNode(parent);
			if (M.find(child) == M.end())
				M[child] = new TreeNode(child);
            if (isLeft)
                M[parent]->left = M[child];
            else
                M[parent]->right = M[child];
            S.insert(child);
        }
		for (int i = 0; i < N; ++i)
		{
			int const& parent = descriptions[i][0];
            if (S.find(parent) == S.end())
                return M[parent];
		}
        return nullptr;
    }
};
