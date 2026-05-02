static int F[13];
static int A[13];
class Solution {
public:
    int evenSumSubgraphs(vector<int>& nums, vector<vector<int>>& edges) {
        int const N = nums.size();
        int result = 0;
        for (int mask = 1; mask < (1 << N); ++mask)
        {
            int isEven = true;
            memset(F, 0, sizeof(F));
            for (int k = 0; k < N; ++k)
                if (mask & (1 << k))
                    isEven ^= nums[k];
            if (!isEven)
                continue;
            for (vector<int> const& e : edges)
            {
                int const V = e[0];
                int const U = e[1];                
                int const VU = (1 << V) | (1 << U);
                if ((VU & mask) == VU)
                {
                    F[V] |= 1 << U;
                    F[U] |= 1 << V;
                }
            }
            for (int k = 0; k < N; ++k)
                if (mask & (1 << k))
                    for (int i = 0; i < N; ++i)
                        if ((mask & (1 << i)) && (F[i] & (1 << k)))
                            F[i] |= F[k];
            for(int k = 0; k < N; ++k)
                if (mask & (1 << k))
                {
                    if ((F[k] | (1 << k)) == mask)
                        ++result;
                    break;
                }
        }
        return result;
    }
};
