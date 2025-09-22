static int F[1'001];
class Solution {
public:
    int validSubarraySplit(vector<int>& nums) {
        int const N = nums.size();
        memset(F, 1, sizeof(F));
        F[0] = 0;
        for (int i = 0; i < N; ++i)
            for (int j = i; j < N; ++j)
                if (F[j + 1] > F[i] + 1 && gcd(nums[i], nums[j]) > 1)
                    F[j + 1] = F[i] + 1;
        if (F[N] > N)
            return -1;
        return F[N];
    }
};
