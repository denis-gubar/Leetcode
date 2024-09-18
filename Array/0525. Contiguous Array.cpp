class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int result = 0;
        int const INF = -2;
        int N = nums.size();
        vector<int> A(N), M(2 * N + 1, INF);
        for (int i = 0; i < N; ++i)
            A[i] = (i > 0 ? A[i - 1] : 0) + nums[i] * 2 - 1;
        M[N] = -1;
        for (int i = 0; i < N; ++i)
            if (M[A[i] + N] == INF)
                M[A[i] + N] = i;
            else
                result = max(result, i - M[A[i] + N]);
        return result;
    }
};
