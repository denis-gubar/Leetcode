static int A[100'002][18];
static int B[100'002][18];
class Solution {
public:
    int binarySearchableNumbers(vector<int>& nums) {
        int result = 0;
        int const N = nums.size();
        for (int i = 0; i < N; ++i)
            A[i][0] = B[i][0] = nums[i];
        for (int j = 1; (1 << j) <= N; ++j)
            for (int i = 0, end = N - (1 << j); i <= end; ++i)
                A[i][j] = min(A[i][j - 1], A[i + (1 << (j - 1))][j - 1]),
                B[i][j] = max(B[i][j - 1], B[i + (1 << (j - 1))][j - 1]);
        auto rmq1 = [](int L, int R)
            {
                if (L == R)
                    return A[L][0];
                int j = 0;
                while (L + (1 << (j + 1)) <= R)
                    ++j;
                return min(A[L][j], A[R - (1 << j) + 1][j]);
            };
        auto rmq2 = [](int L, int R)
            {
                if (L == R)
                    return B[L][0];
                int j = 0;
                while (L + (1 << (j + 1)) <= R)
                    ++j;
                return max(B[L][j], B[R - (1 << j) + 1][j]);
            };

        for (int i = 0; i < N; ++i)
            if (rmq2(0, i) == rmq1(i, N - 1))
                ++result;
        return result;
    }
};
