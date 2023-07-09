class Solution {
public:
    int bitCount(long long x)
    {
        int result = 0;
        while (x)
        {
            ++result;
            x &= x - 1;
        }
        return result;
    }
    int makeTheIntegerZero(int num1, int num2) {
        long long x = num1, y = num2;
        for (int i = 1; i <= 40; ++i)
        {
            long long r = x - i * y;
            if (r <= 0)
                break;
            if (i >= bitCount(r) && i <= r)
                return i;
        }
        return -1;
    }
};
