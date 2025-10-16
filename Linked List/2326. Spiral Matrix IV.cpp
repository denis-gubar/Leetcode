/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int N, int M, ListNode* head) {
        vector<vector<int>> result(N, vector<int>(M, -1));
        int x = 0, y = -1, d = 0;
        int kx = N, ky = M;
        vector<int> dx{ 0, 1, 0, -1 };
        vector<int> dy{ 1, 0, -1, 0 };
        while (head && ky)
        {
            for (int k = 0; k < ky; ++k)
            {
                x += dx[d], y += dy[d];
                if (head)
                {
                    result[x][y] = head->val;
                    head = head->next;
                }
                else
                    break;
            }
            d = (d + 1) % 4;
            swap(kx, ky);
            --ky;
        }
        return result;
    }
};
