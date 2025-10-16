class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        long long result = -1;
        int N = nums.size();
        vector<long long> A(N + 1);
        sort(nums.begin(), nums.end());
        for (int i = 0; i < N; ++i)
            A[i + 1] = A[i] + nums[i];
        for(int i = N - 1; i > 1; --i)
        {
            if (nums[i] < A[i] && (result == -1 || result < nums[i] + A[i]))
                result = nums[i] + A[i];
        }
        return result;
    }
};
