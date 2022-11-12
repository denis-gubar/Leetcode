class Solution {
public:
    int bitcount(int x)
    {
        int result = 0;
        while (x)
        {
            ++result;
            x &= x - 1;
        }
        return result;
    }
    int minimizeXor(int num1, int num2) {
        int result = 0;
        int K = bitcount(num2);
        int N = bitcount(num1);
        for (int k = 0; K > N && k < 30; ++k)
            if ((num1 & (1 << k)) == 0)
                result |= 1 << k, --K;
        for (int k = 30; k >= 0; --k)
            if ((num1 & (1 << k)) > 0)
            {
                if (K > 0)
                    --K;
                else
                    result |= 1 << k;
            }
        return result ^ num1;
    }
};
