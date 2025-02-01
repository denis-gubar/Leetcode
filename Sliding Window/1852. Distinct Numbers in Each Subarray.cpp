static int M[100'001];
class Solution {
public:
    vector<int> distinctNumbers(vector<int>& nums, int K) {
        int const N = nums.size();
        vector<int> result(N - K + 1);
        memset(M, 0, sizeof(M));
        int distinctCount = 0;
        for (int i = 0; i < N; ++i)
        {
            int const& value = nums[i];
            if (++M[value] == 1)
                ++distinctCount;
            if (i >= K)
            {
                int const& value = nums[i - K];
                if (--M[value] == 0)
                    --distinctCount;
            }
            if (i >= K - 1)
                result[i - K + 1] = distinctCount;
        }
        return result;
    }
};
