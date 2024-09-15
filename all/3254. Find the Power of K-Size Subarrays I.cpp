static char F[100'002][18];
class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        if (k == 1)
            return nums;
        int const N = nums.size();
        vector<int> result;
        result.reserve(N);
        for (int i = 0; i < N; ++i)
            F[i][0] = (i == 0 || nums[i] == nums[i - 1] + 1);
        for (int j = 1; (1 << j) <= N; ++j)
            for (int i = 0, end = N - (1 << j); i <= end; ++i)
                F[i][j] = min(F[i][j - 1], F[i + (1 << (j - 1))][j - 1]);
        auto rmq = [](int L, int R)
            {
                if (L == R)
                    return F[L][0];
                int j = 0;
                while (L + (1 << (j + 1)) <= R)
                    ++j;
                return min(F[L][j], F[R - (1 << j) + 1][j]);
            };
        for (int i = 0; i + k <= N; ++i)
        {
            if (rmq(i + 1, i + k - 1))
                result.push_back(nums[i + k - 1]);
            else
                result.push_back(-1);
        }
        return result;
    }
};
