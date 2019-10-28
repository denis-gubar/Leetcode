/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    TreeLinkNode* find( TreeLinkNode* root, int path )
    {
        vector<int> bits;
        while (path > 1)
        {
            bits.push_back( path & 1 );
            path >>= 1;
        }
        TreeLinkNode* result = root;
        reverse( bits.begin(), bits.end() );
        for (const auto& bit : bits)
            result = bit ? result->right : result->left;
        return result;
    }
    void connect( TreeLinkNode* root ) {
        if (!root)
            return;
        int height = 1;
        TreeLinkNode* node = root;
        while (node->right)
        {
            node = node->right;
            ++height;
        }
        for (int level = height; level > 0; --level)
        {
            TreeLinkNode* nextNode = nullptr;
            for (int nodeNumber = (1 << level) - 1; nodeNumber >= (1 << (level - 1)); --nodeNumber)
            {
                TreeLinkNode* currentNode = find( root, nodeNumber );
                if (nodeNumber + 1 == (1 << level))
                    nextNode = currentNode;
                else
                {
                    currentNode->next = nextNode;
                    nextNode = currentNode;
                }
            }
        }
    }
};