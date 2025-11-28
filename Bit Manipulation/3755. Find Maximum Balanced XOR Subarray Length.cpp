static int A[100'001];
static int B[100'001];
class Solution {
public:
    int maxBalancedSubarray(vector<int>& nums) {
        int result = 0;
        int const N = nums.size();
        A[0] = B[0] = 0;
        unordered_map<long long, int> M;
        M[N] = -1;
        for (int i = 0; i < N; ++i)
        {
            A[i + 1] = A[i] ^ nums[i], B[i + 1] = B[i] + (nums[i] % 2 == 0) - (nums[i] % 2 == 1);
            long long hash = (1LL * A[i + 1] << 32L) | (N + B[i + 1]);
            if (M.find(hash) != M.end())
                result = max(result, i - M[hash]);
            else
                M[hash] = i;
        }
        return result;
    }
};
