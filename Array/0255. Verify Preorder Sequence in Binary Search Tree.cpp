class Solution {
public:
    vector<int> preorder;
    bool calc(int A, int B, int left, int right)
    {
        if (left > right)
            return true;
        int const& root = preorder[left];
        if (left == right)
            return A < root && root < B;
        if (root <= A || root >= B)
            return false;
        int leftBranch = left;
        while (leftBranch < right && preorder[leftBranch + 1] < root)
        {
            ++leftBranch;
            if (A >= preorder[leftBranch])
                return false;
        }
        int rightBranch = leftBranch;
        while (rightBranch < right && preorder[rightBranch + 1] > root)
        {
            ++rightBranch;
            if (preorder[rightBranch] >= B)
                return false;
        }
        if (rightBranch < right)
            return false;
        return calc(A, root, left + 1, leftBranch) && calc(root, B, leftBranch + 1, right);
    }
    bool verifyPreorder(vector<int>& preorder) {
        int const N = preorder.size();
        this->preorder = preorder;
        return calc(-1, 10'001, 0, N - 1);
    }
};
