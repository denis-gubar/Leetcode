static bool isInit = false;
static vector<bool> isPrime(1'000'000, 1);
static void init()
{
    if (!isInit)
    {
        isInit = true;
        isPrime[1] = isPrime[0] = 0;
        for (int i = 2; i * i < 1'000'000; ++i)
            if (isPrime[i])
                for (int k = i * i; k < 1'000'000; k += i)
                    isPrime[k] = 0;
    }
}
class Solution {
public:
    int maximumPrimeDifference(vector<int>& nums) {
        init();
        int N = nums.size();
        vector<int> A;
        A.reserve(N);
        for (int i = 0; i < N; ++i)
            if (isPrime[nums[i]])
                A.push_back(i);
        return A.back() - A[0];
    }
};
