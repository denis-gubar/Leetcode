static int F[200'000];
class Solution {
public:
    int minChanges(vector<int>& nums, int K) {
        int const N = nums.size();
        int result = 2 * N;
        memset(F, 0, sizeof(F));
        for (int a = 0, b = N - 1; a < b; ++a, --b)
        {
            int delta = abs(nums[a] - nums[b]);
            int x = max(K - min(nums[a], nums[b]), max(nums[a], nums[b]));
            ++F[0];
            --F[delta];
            ++F[delta + 1];
            ++F[x + 1];
        }
        int sum = 0;
        for (int i = 0; i <= K + 2; ++i)
            sum += F[i], result = min(result, sum);
        return result;
    }
};
