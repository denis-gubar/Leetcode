class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int result = 1;
        int const N = nums.size();
        nums.push_back(nums.back() - 1);
        vector<int> A;
        A.reserve(N);
        for (int i = 1, count = 1; i <= N; ++i)
            if (nums[i - 1] >= nums[i])
                A.push_back(count), count = 1;
            else
                ++count;
        int const M = A.size();
        for (int x : A)
            result = max(result, x / 2);
        for (int i = 1; i < M; ++i)
            result = max(result, min(A[i - 1], A[i]));
        return result;
    }
};
