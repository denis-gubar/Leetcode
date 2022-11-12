class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        vector<int> result;
        int N = nums.size();
        vector<int> A(N), B(N);
        A[0] = 1;
        B[0] = 1;
        for (int i = 1; i < N; ++i)
        {
            if (nums[i] >= nums[i - 1])
                A[i] = A[i - 1] + 1;
            else
                A[i] = 1;
            if (nums[i] <= nums[i - 1])
                B[i] = B[i - 1] + 1;
            else
                B[i] = 1;
        }
        for (int i = k; i < N - k; ++i)
            if (A[i + k] >= k && B[i - 1] >= k)
                result.push_back(i);
        return result;
    }
};
