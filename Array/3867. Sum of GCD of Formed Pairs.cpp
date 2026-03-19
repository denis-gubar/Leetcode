static int MX[100'000];
static int P[100'000];
class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        long long result = 0;
        int const N = nums.size();
        P[0] = MX[0] = nums[0];
        for (int i = 1; i < N; ++i)
            MX[i] = max(MX[i - 1], nums[i]), P[i] = gcd(nums[i], MX[i]);
        sort(&P[0], &P[0] + N);
        for (int a = 0, b = N - 1; a < b; ++a, --b)
            result += gcd(P[a], P[b]);
        return result;
    }
};
