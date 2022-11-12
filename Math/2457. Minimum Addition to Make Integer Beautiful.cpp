class Solution {
public:
    long long makeIntegerBeautiful(long long n, int target) {
        long long result = 0;
        vector<int> digits;
        long long x = n;
        while (x)
        {
            digits.push_back(x % 10);
            x /= 10;
        }
        reverse(digits.begin(), digits.end());
        int N = digits.size();
        int sum = target + 1;
        while (sum > target)
        {
            sum = 0;
            int last = 0;
            for (int i = 0; i < N; ++i)
                if (sum + digits[i] <= target)
                {
                    sum += digits[i];
                    ++last;
                }
                else
                    break;
            if (last < N)
            {
                for (int i = last; i < N; ++i)
                    digits[i] = 0;
                int i = last - 1;
                if (i >= 0)
                {
                    ++digits[i];
                    ++sum;
                }
                else
                {
                    digits[0] = 10;
                    sum = 1;
                }
                while (i > 0 && digits[i] == 10)
                {
                    digits[i] = 0;
                    sum -= 9;
                    --i;
                    ++digits[i];
                }
                if (i == 0 && digits[i] == 10)
                    sum -= 9;
            }
        }
        for (int i = 0; i < N; ++i)
            result = result * 10 + digits[i];
        return result - n;
    }
};
