class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long result = 0;
        int const N = nums.size();
        vector<int> A(30, -1);
        for (int i = 0; i < N; ++i)
        {
            int const x = nums[i];
            for (int j = 0; j < 30; ++j)
                if ((x & (1 << j)) == 0)
                    A[j] = i;
            if ((x & k) == k)
            {
                int L = -1, R = i;
                for (int j = 0; j < 30; ++j)
                    if (k & (1 << j))
                        L = max(L, A[j]);
                    else
                        R = min(R, A[j]);
                if (L < R)
                    result += R - L;
            }
        }
        return result;
    }
};
