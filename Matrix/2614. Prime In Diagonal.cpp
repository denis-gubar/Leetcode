class Solution {
public:
    int diagonalPrime(vector<vector<int>>& nums) {
        int result = 0;
        vector<bool> isPrime(4'000'001, true);
        isPrime[1] = isPrime[0] = false;
        for (int i = 2; i * i < 4'000'001; ++i)
            if (isPrime[i])
                for (int k = i * i; k < 4'000'001; k += i)
                    isPrime[k] = false;
        int N = nums.size();
        for (int i = 0; i < N; ++i)
        {
            int x = nums[i][i];
            if (isPrime[x])
                result = max(result, x);
            x = nums[i][N - i - 1];
            if (isPrime[x])
                result = max(result, x);
        }
        return result;
    }
};
