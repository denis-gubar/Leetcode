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
    void calc(TreeNode* root, vector<vector<int>>& connectivity)
    {
        if (!root) return;
        int V = root->val;
        if (root->left)
        {
            int U = root->left->val;
            connectivity[V].push_back(U);
            connectivity[U].push_back(V);
            calc(root->left, connectivity);
        }
        if (root->right)
        {
            int U = root->right->val;
            connectivity[V].push_back(U);
            connectivity[U].push_back(V);
            calc(root->right, connectivity);
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        vector<vector<int>> connectivity(100'001);
        calc(root, connectivity);
        vector<bool> visited(100'001);
        visited[start] = true;
        queue<int> Q;
        Q.push(start); Q.push(0);
        int result = 0;
        while (!Q.empty())
        {
            int V = Q.front(); Q.pop();
            int T = Q.front(); Q.pop();
            result = max(result, T);
            for(int U: connectivity[V])
                if (!visited[U])
                {
                    visited[U] = true;
                    Q.push(U); Q.push(T + 1);
                }
        }
        return result;
    }
};
