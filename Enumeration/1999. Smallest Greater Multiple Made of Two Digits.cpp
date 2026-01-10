class Solution {
public:
    int findInteger(int K, int digit1, int digit2) {
        int D[2] = { min(digit1, digit2), max(digit1, digit2) };
        for (int length = 1; length < 12; ++length)
            for (int mask = 0; mask < (1 << length); ++mask)
            {
                long long value = 0;
                for (int k = 0; k < length; ++k)
                    value = value * 10 + D[(mask & (1 << (length - k - 1))) > 0];
                if (value >= INT_MAX)
                    return -1;
                if (value > K && value % K == 0)
                    return value;
            }
        return -1;
    }
};
