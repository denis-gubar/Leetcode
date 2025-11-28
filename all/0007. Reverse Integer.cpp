class Solution {
public:
    int reverse(int x) {
        int sign = 1;
        if (x == -2147483648)
            return 0;
        if (x < 0)
            sign = -1, x *= -1;
        int const MAX = 0x7FFFFFFF;
        int result = 0;
        while(x > 0)
        {
            if (result * 10.0 + x % 10 > MAX)
                return 0;
            result = result * 10 + x % 10;
            x /= 10;
        }
        return sign * result;
    }
};