class Solution {
public:
    bool check(long long x)
    {
        long long y = x;
        long long reversed = 0;
        while (x > 0)
            reversed = reversed * 10 + x % 10, x /= 10;
        return y == reversed;
    }
    int largestPalindrome(int N) {
        int const MOD = 1'337;
        long long result = 0;
        if (N == 1)
            return 9;
        if (N % 2 == 0)
            result = stoll(string(N, '9')) * stoll(string(N / 2, '9') + string(N / 2 - 1, '0') + '1');
        else
        {
            int maxX = stoi(string(N, '9'));
            int minX = stoi('9' + string(N - 1, '0'));
            for (int x = maxX, e = max(minX, maxX - 2500); x >= e; --x)
                for (int y = x; y >= e; --y)
                    if (result < 1LL * x * y && check(1LL * x * y))
                        result = 1LL * x * y;
        }
        return result % MOD;
    }
};
