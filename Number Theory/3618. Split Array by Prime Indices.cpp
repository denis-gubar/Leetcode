bool static isInit = false;
static vector<bool> isPrime(100'001, 1);
static void init()
{
    if (!isInit)
    {
        isInit = true;
        isPrime[1] = isPrime[0] = 0;
        for (int i = 2; i * i < 100'001; ++i)
            if (isPrime[i])
                for (int k = i * i; k < 100'001; k += i)
                    isPrime[k] = 0;    }
}
class Solution {
public:
    long long splitArray(vector<int>& nums) {
        init();
        long long result = 0;
        int const N = nums.size();
        for (int i = 0; i < N; ++i)
            if (isPrime[i])
                result += nums[i];
            else
                result -= nums[i];
        return abs(result);
    }
};
