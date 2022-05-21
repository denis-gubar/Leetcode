class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int N = nums.size();
        int result = 0;
        vector<long long> A(N);
        for (int i = 0; i < N; ++i)
        {
            A[i] += nums[i];
            if (i > 0)
                A[i] += A[i - 1];
        }
        for (int i = 0; i < N - 1; ++i)
            result += A[i] >= (A[N - 1] - A[i]);
        return result;
    }
};
