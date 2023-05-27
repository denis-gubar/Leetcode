class Solution {
public:
    int const MOD = 1'000'000'007;
    int power(int x, int n)
    {
        if (n == 0)
            return 1;
        if (n == 1)
            return x;
        long long result = x;
        long long extra = 1;
        while (n > 1)
        {
            if (n % 2)
            {
                extra *= result;
                extra %= MOD;
            }
            result *= result;
            result %= MOD;
            n /= 2;
        }
        return result * extra % MOD;
    }
    int numSubseq(vector<int>& nums, int target) {
        int N = nums.size();
        int result = 0;
        nums.push_back(target + 1);
        sort(nums.begin(), nums.end());
        int a = 0, b = N;
        while (true)
        {
            while (a <= b && nums[a] + nums[b] > target)
                --b;
            if (a > b)
                break;
            result += power(2, b - a);
            result %= MOD;
            ++a;
        }
        return result;
    }
};
