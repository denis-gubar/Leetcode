static bool isInit = false;
static vector<bool> isPrime(101'001, true);
static void init()
{
    if (!isInit)
    {
        isInit = true;
        isPrime[1] = isPrime[0] = false;
        for (int i = 2; i * i < 101'001; ++i)
            if (isPrime[i])
                for (int k = i * i; k < 101'001; k += i)
                    isPrime[k] = false;
    }
}
class Solution {
public:
    int minOperations(vector<int>& nums) {
        init();
        int result = 0;
        int const N = nums.size();
        for (int i = 0; i < N; ++i)
        {
            int x = nums[i];
            while ((i % 2) + isPrime[x] != 1)
                ++x, ++result;
        }
        return result;
    }
};
