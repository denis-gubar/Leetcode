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
    bool calc(double target, int k, deque<int>& D, TreeNode* root)
    {
        if (!root) return true;
        if (!calc(target, k, D, root->left))
            return false;
        int const& x = root->val;
        if (x < target)
        {
            D.push_front(x);
            if (D.size() > k)
                D.pop_back();
        }
        else
        {
            D.push_front(x);
            if (D.size() > k)
            {
                if (abs(D.front() - target) >= abs(target - D.back()))
                {
                    D.pop_front();
                    return false;
                }
                D.pop_back();
            }
        }
        return calc(target, k, D, root->right);
    }
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        deque<int> D;        
        calc(target, k, D, root);
        return vector<int>(D.begin(), D.end());
    }
};
