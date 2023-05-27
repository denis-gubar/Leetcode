static double F[20'000];
class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        memset(F, 0, sizeof(F));
        F[0] = 1.0;
        double balance = 0.0;
        for (int i = 1; i < k + maxPts; ++i)
        {
            if (i <= k)
                balance += F[i - 1] / maxPts;
            if (i > maxPts)
                balance -= F[i - maxPts - 1] / maxPts;
            F[i] = balance;
        }
        double result = 0.0;
        for (int i = k; i <= n; ++i)
            result += F[i];
        return result;
    }
};
