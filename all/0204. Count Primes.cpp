class Solution {
public:
    int countPrimes(int N) {
        int result = 0;
        vector<bool> isPrime(N + 1, true);
        for(int k = 2; k * k <= N; ++k)
            for(int i = k * 2; i <= N; i += k)
                isPrime[i] = false;
        for(int i = 2; i < N; ++i)
            result += isPrime[i];
        return result;
    }
};