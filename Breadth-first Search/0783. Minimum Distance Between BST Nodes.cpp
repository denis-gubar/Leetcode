class Solution {
public:
    vector<int> A;
    void calc( TreeNode* root )
    {
        if (root)
        {
            A.push_back( root->val );
            calc( root->left );
            calc( root->right );
        }
    }
    int minDiffInBST( TreeNode* root ) {
        A = vector<int>();
        calc(root);
        sort( A.begin(), A.end() );
        int result = A[1] - A[0];
        for (int i = 2; i < A.size(); ++i)
            result = min( result, A[i] - A[i - 1] );
        return result;
    }
};