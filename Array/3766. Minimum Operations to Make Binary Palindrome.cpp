static short F[10'000];
static short COUNT = 0;
static bool isInit = false;
static void init()
{
    if (!isInit)
    {
        isInit = true;
        memset(F, 0, sizeof(F));
        ++COUNT;
        F[COUNT] = 1;
        ++COUNT;
        for (int short i = 2; i <= 10'000; ++i)
        {
            short result = 0, x = i;
            while (x > 0)
            {
                result = result * 2 + x % 2;
                x /= 2;
            }
            if (result == i)
                F[COUNT] = i, ++COUNT;
        }
    }
}
class Solution {
public:
    vector<int> minOperations(vector<int>& nums) {
        init();
        int const N = nums.size();
        vector<int> result(N);
        for (int i = 0; i < N; ++i)
        {
            auto it = lower_bound(&F[0], &F[0] + COUNT, nums[i]);
            result[i] = min(*it - nums[i], nums[i] - *(prev(it)));
        }
        return result;
    }
};
