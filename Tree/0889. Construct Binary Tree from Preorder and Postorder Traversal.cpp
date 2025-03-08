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
    vector<int> preorder;
    vector<int> postorder;
    TreeNode* calc(int a, int b, int c, int d)
    {
        if (a == b)
            return nullptr;
        TreeNode* root = new TreeNode(preorder[a]);
        set<int> A, B;
        int left_length = 0;
        for (; left_length + 1 < b - a; ++left_length)
        {
            A.insert(preorder[a + 1 + left_length]);
            B.insert(postorder[c + left_length]);
            if (A == B)
            {
                ++left_length;
                break;
            }
        }
        root->left = calc(a + 1, a + left_length + 1, c, c + left_length);
        root->right = calc(a + left_length + 1, b, c + left_length, d - 1);
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        this->preorder = preorder;
        this->postorder = postorder;
        int const N = preorder.size();
        return calc(0, N, 0, N);
    }
};
