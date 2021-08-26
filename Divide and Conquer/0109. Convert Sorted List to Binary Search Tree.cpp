/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* calc( ListNode* head, ListNode* tail )
    {
        if (!head || head == tail)
            return nullptr;
        ListNode* median = head;
        ListNode* end = head->next;
        while (end != tail)
        {
            median = median->next;
            end = end->next;
            if (end != tail)
                end = end->next;
        }
        TreeNode* root = new TreeNode( median->val );
        root->left = calc( head, median );
        root->right = calc( median->next, end );
        return root;
    }
    TreeNode* sortedListToBST( ListNode* head ) {
        return calc( head, nullptr );
    }
};