/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int numComponents( ListNode* head, vector<int>& G ) {
        int result = 0;
        set<int> S( G.begin(), G.end() );
        bool found = false;
        while (head)
        {
            if (S.find( head->val ) != S.end())
            {
                S.erase( head->val );
                if (!found)
                {
                    ++result;
                    found = true;
                }
            }
            else
                found = false;
            head = head->next;
        }
        return result;
    }
};