class Solution {
public:
    int maxChunksToSorted( vector<int>& arr ) {
        vector<int> A( arr ), B( arr ), C( arr );
        sort( B.begin(), B.end() );
        int Max = A[0];
        for (int i = 0; i < A.size(); ++i)
        {
            if (Max < A[i])
                Max = A[i];
            C[i] = Max;
        }
        int result = 0;
        int pos = 0;
        Max = -1;
        int maxCount = 0;
        while (pos < A.size())
        {
            while (B[pos] != C[pos] || maxCount)
            {
                if (Max < A[pos])
                    Max = A[pos], maxCount = 1;
                ++pos;
                if (Max == A[pos])
                    ++maxCount;
                if (B[pos] == C[pos])
                    --maxCount;
            }
            ++result;
            ++pos;
        }
        return result;
    }
};