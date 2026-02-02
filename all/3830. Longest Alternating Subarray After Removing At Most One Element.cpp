class Solution {
public:
    int longestAlternating(vector<int>& nums) {
        int result = 1;
        int const N = nums.size();
        vector<int> A(N + 1), B(N + 1);
        for (int i = N - 2; i >= 0; --i)
        {
            if (nums[i] < nums[i + 1])
            {
                A[i] = 2;
                if (B[i + 1] > 0)
                    A[i] = B[i + 1] + 1;     
                int x = A[i] / 2 * 2;
                if (i + x + 1 < N && nums[i + x - 1] > nums[i + x + 1])
                    result = max(result, x + max(1, A[i + x + 1]));
                x = A[i];
                if (x % 2 == 0)
                    --x;
                if (i + x + 1 < N && nums[i + x - 1] < nums[i + x + 1])
                    result = max(result, x + max(1, B[i + x + 1]));
                result = max(result, A[i]);
            }
            else if (nums[i] > nums[i + 1])
            {
                B[i] = 2;
                if (A[i + 1] > 0)
                    B[i] = A[i + 1] + 1;
                int x = B[i] / 2 * 2;
                if (i + x + 1 < N && nums[i + x - 1] < nums[i + x + 1])
                    result = max(result, x + max(1, B[i + x + 1]));
                x = B[i];
                if (x % 2 == 0)
                    --x;
                if (i + x + 1 < N && nums[i + x - 1] > nums[i + x + 1])
                    result = max(result, x + max(1, A[i + x + 1]));
                result = max(result, B[i]);
            }
        }
        return result;
    }
};
