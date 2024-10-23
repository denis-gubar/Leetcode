static bool isInit = false;
static int D[1'000'001];
static void init()
{
    if (!isInit)
    {
        isInit = true;
        memset(D, 0, sizeof(D));
        for (int i = 4; i <= 1'000'000; ++i)
            for (int k = 2; k * k <= i; ++k)
                if (i % k == 0)
                {
                    D[i] = k;
                    break;
                }
    }
}
class Solution {
public:
    int minOperations(vector<int>& nums) {
        init();
        int const N = nums.size();
        int result = 0;
        for (int i = N - 2; i >= 0; --i)
        {
            while (nums[i] > nums[i + 1] && D[nums[i]] > 0)
                nums[i] = D[nums[i]], ++result;
            if (nums[i] <= nums[i + 1])
                continue;
            else
                return -1;
        }
        return result;
    }
};
