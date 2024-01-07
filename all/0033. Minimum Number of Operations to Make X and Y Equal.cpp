static int F[10'011];
class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
        if (y >= x)
            return y - x;
        int result = x - y;
        memset(F, 1, sizeof(F));
        F[x] = 0;
        for (int i = x; i > 0; --i)
        {
            result = min(result, F[i] + abs(i - y));
            if (i % 11 > 0)
                F[i / 11 + 1] = min(F[i / 11 + 1], F[i] + 12 - i % 11);
            if (i % 5 > 0)
                F[i / 5 + 1] = min(F[i / 5 + 1], F[i] + 6 - i % 5);
            F[i / 11] = min(F[i / 11], i % 11 + 1 + F[i]);
            F[i / 5] = min(F[i / 5], i % 5 + 1 + F[i]);
            if (i % 5 == 0)
                F[i / 5] = min(F[i / 5], 1 + F[i]);
            F[i - 1] = min(F[i - 1], 1 + F[i]);
        }
        return result;
    }
};
