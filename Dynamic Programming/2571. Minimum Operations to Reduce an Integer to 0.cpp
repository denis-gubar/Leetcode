class Solution {
public:
    static int numberOfSetBits(uint32_t i)
    {
        i = i - ((i >> 1) & 0x55555555);
        i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
        i = (i + (i >> 4)) & 0x0F0F0F0F;
        i *= 0x01010101;
        return  i >> 24;
    }
    int minOperations(int n) {
        int result = numberOfSetBits(n);
        int x = 1, N = 0;
        while (x < n)
            x <<= 1, ++N;
        for (int mask = 1; mask < (1 << N); ++mask)
        {
            x = n + mask;
            result = min(result, numberOfSetBits(mask) + numberOfSetBits(x));
        }
        return result;
    }
};
