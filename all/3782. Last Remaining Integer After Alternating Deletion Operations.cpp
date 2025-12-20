class Solution {
public:
    long long lastInteger(long long n) {
        long long a = 1, b = n, step = 1;
        while (a < b)
        {
            b = a + (b - a) / (2 * step) * 2 * step;
            step *= 2;
            if (a == b)
                break;
            a = b - (b - a) / (2 * step) * 2 * step;
            step *= 2;
        }
        return a;
    }
};
