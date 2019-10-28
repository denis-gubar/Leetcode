class Solution {
public:
    bool isIdealPermutation( vector<int>& A ) {
        for (int i = 0; i + 1 < A.size(); ++i)
            if (A[i] > A[i + 1])
            {
                if (A[i] == 1 + A[i + 1])
                    swap( A[i], A[i + 1] );
                else
                    return false;
            }
        return true;
    }
};