class Solution {
public:
    bool checkPrimeFrequency(vector<int>& nums) {
        vector<bool> isPrime(101, true);
        isPrime[1] = isPrime[0] = false;
        for (int i = 2; i * i < 101; ++i)
            if (isPrime[i])
                for (int k = i * i; k < 101; k += i)
                    isPrime[k] = false;
        unordered_map<int, int> M;
        for (int x : nums)
            ++M[x];
        bool result = false;
        for (auto [key, value] : M)
            result |= isPrime[value];
        return result;
    }
};
