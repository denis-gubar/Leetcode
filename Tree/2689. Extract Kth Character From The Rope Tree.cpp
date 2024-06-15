/**
 * Definition for a rope tree node.
 * struct RopeTreeNode {
 *     int len;
 *     string val;
 *     RopeTreeNode *left;
 *     RopeTreeNode *right;
 *     RopeTreeNode() : len(0), val(""), left(nullptr), right(nullptr) {}
 *     RopeTreeNode(string s) : len(0), val(std::move(s)), left(nullptr), right(nullptr) {}
 *     RopeTreeNode(int x) : len(x), val(""), left(nullptr), right(nullptr) {}
 *     RopeTreeNode(int x, RopeTreeNode *left, RopeTreeNode *right) : len(x), val(""), left(left), right(right) {}
 * };
 */
class Solution {
public:
    char getKthCharacter(RopeTreeNode* root, int k) {
        if (root->len == 0)
            return root->val[k - 1];
        int left = 0;
        if (root->left)
        {
            if (root->left->len >= k || root->left->val.size() >= k)
                return getKthCharacter(root->left, k);
            left = max<int>(root->left->len, root->left->val.size());
        }
        return getKthCharacter(root->right, k - left);
    }
};