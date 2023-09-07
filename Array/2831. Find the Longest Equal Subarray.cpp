class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        int N = nums.size();
        int result = 0;
        vector<vector<int>> A(100'001);
        vector<int> L(100'001, -1), R(100'001, -1);
        for (int i = 0; i < N; ++i)
            A[nums[i]].push_back(i);
        auto calc = [&A](int x, int left, int right)
        {
            if (left == right)
                return 0;
            int result = A[x][right] - A[x][left] - 1;
            result -= right - left - 1;
            return result;
        };
        for (int i = 0; i + result < N; ++i)
        {
            int const& x = nums[i];
            ++L[x];
            if (R[x] + 1 == A[x].size())
                continue;
            while (R[x] + 1 < A[x].size() && calc(x, L[x], R[x] + 1) <= k)
                ++R[x];
            result = max(result, A[x][R[x]] - A[x][L[x]] + 1 - calc(x, L[x], R[x]));
        }
        return result;
    }
};
