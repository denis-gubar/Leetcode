static long long F[2'000];
static int maxLength[2'000];
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int result = 0;
        int const N = nums.size();
        fill(&F[0], &F[0] + N, 1);
        fill(&maxLength[0], &maxLength[0] + N, 1);
        for(int i = 0; i < N; ++i)
            for(int j = i + 1; j < N; ++j)
                if (nums[j] > nums[i])
                {
                    if (maxLength[j] <= maxLength[i])
                    {
                        maxLength[j] = maxLength[i] + 1;
                        F[j] = F[i];
                    }
                    else if (maxLength[j] == maxLength[i] + 1)
                    {
                        F[j] += F[i];
                        F[j] %= 1LL << 32;
                    }
                }
        int bestLength = *max_element(&maxLength[0], &maxLength[0] + N);
        for (int i = 0; i < N; ++i)
            if (maxLength[i] == bestLength)
                result += F[i];
        return result;
    }
};
