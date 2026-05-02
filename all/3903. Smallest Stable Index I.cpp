static int A[100'000];
class Solution {
public:
    int firstStableIndex(vector<int>& nums, int K) {
        int const N = nums.size();
        A[N - 1] = nums[N - 1];
        for (int i = N - 2; i >= 0; --i)
            A[i] = min(A[i + 1], nums[i]);
        int B = nums[0];
        for (int i = 0; i < N; ++i)
        {
            B = max(B, nums[i]);
            if (B - A[i] <= K)
                return i;
        }
        return -1;
    }
};
