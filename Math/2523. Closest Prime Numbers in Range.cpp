class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> isPrime(1'000'001, true);
        isPrime[1] = isPrime[0] = false;
        int primeCount = 0;
        for (int i = 2; i < 1'000'001; ++i)
            if (isPrime[i])
            {
                for (long long k = 1LL * i * i; k <= 1'000'000; k += i)
                    isPrime[k] = false;
            }
        vector<int> A;
        for (int x = left; x <= right; ++x)
            if (isPrime[x])
                A.push_back(x);
        if (A.size() < 2)
            return { -1, -1 };
        vector<int> result = { A[0], A[1] };
        for (int i = 2; i < A.size(); ++i)
            if (A[i] - A[i - 1] < result[1] - result[0])
                result[0] = A[i - 1], result[1] = A[i];
        return result;
    }
};
