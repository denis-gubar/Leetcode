class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        int result = 0;
        vector<bool> isPrime(1'001, true);
        isPrime[1] = isPrime[0] = false;
        int primeCount = 0;
        for (int i = 2; i < 1'000; ++i)
            if (isPrime[i])
            {
                for (int k = i * i; k <= 1'000; k += i)
                    isPrime[k] = false;                
            }
        for(int i = 2; i < 1'001; ++i)
            if (isPrime[i])
            {
                for(int x : nums)
                    if (x % i == 0)
                    {
                        ++result;
                        break;
                    }
            }
        return result;
    }
};
