class Solution {
public:
    long long countQuadruplets(vector<int>& nums) {
        long long result = 0;
        for (int& x : nums)
            --x;
        int N = nums.size();
        vector<vector<int>> A(N + 1, vector<int>(N + 1));
        vector<vector<int>> B(N + 1, vector<int>(N + 1));
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                A[i][j] = (i > 0 ? A[i - 1][j] : 0) + (nums[i] <= j);
        for (int i = N - 1; i >= 0; --i)
            for (int j = 0; j < N; ++j)
                B[i][j] = (i < N - 1 ? B[i + 1][j] : 0) + (nums[i] >= j);
        for (int j = 1; j + 2 < N; ++j)
            for (int k = j + 1; k + 1 < N; ++k)
                if (nums[j] > nums[k])
                    result += A[j - 1][nums[k]] * B[k + 1][nums[j]];
        return result;
    }
};
