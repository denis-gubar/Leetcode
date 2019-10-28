class Solution {
public:
    int numSubarrayBoundedMax( vector<int>& A, int L, int R ) {
        int result = 0;
        int a = 0, b = 0, x = 0, z = 0;
        while (b < A.size())
        {
            if (A[b] <= R)
            {
                if (a < 0)
                    a = b;
                if (A[b] >= L)
                {
                    z = 0;
                    ++x;
                }
                else
                    ++z;
                if (A[b] >= L)
                    result += b - a + 1;
                else
                    result += b - a + 1 - z;
            }
            else 
            {
                a = -1;
                x = 0;
                z = 0;
            }
            ++b;
        }
        return result;
    }
};