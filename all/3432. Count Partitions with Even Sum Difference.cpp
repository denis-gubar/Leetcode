class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int result = 0;
        int const N = nums.size();
        vector<int> A(N + 1);
        for (int i = 0; i < N; ++i)
            A[i + 1] = A[i] + nums[i] % 2;
        for (int i = 0; i < N - 1; ++i)
            result += (A[i + 1] - A[N] + A[i + 1] + 100) % 2 == 0;
        return result;
    }
};
