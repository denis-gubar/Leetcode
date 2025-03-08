class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> isPrime(right + 1, true);
        isPrime[1] = isPrime[0] = false;
        int primeCount = 0;
        for (int i = 2; i * i <= right; ++i)
            if (isPrime[i])
            {
                for (int k = i * i; k <= right; k += i)
                    isPrime[k] = false;
            }
        vector<int> result = { -1, -1 };
        int best = right - left + 1, last = -1;
        for (int x = left; x <= right; ++x)
            if (isPrime[x])
            {
                if (last > 0)
                {
                    if (x - last < best)
                        best = x - last, result[0] = last, result[1] = x;
                }
                last = x;
            }
        return result;
    }
};
