static long long A[100'001];
class Solution {
public:
    long long splitArray(vector<int>& nums) {
        long long const INF = 1LL << 40;
        long long result = INF;
        int const N = nums.size();
        A[0] = 0;
        for (int i = 0; i < N; ++i)
            A[i + 1] = A[i] + nums[i];
        int R = 0;
        while (R + 1 < N && nums[R] < nums[R + 1])
            ++R;
        int L = N - 1;
        while (L > 0 && nums[L] < nums[L - 1])
            --L;
        for (int i = 0; i <= R; ++i)
            if (i + 1 >= L)
                result = min(result, abs(A[i + 1] - (A[N] - A[i + 1])));
        if (result == INF)
            result = -1;
        return result;
    }
};
