static bool isInit = false;
static double F[201];
static void init()
{
    if (!isInit)
    {
        isInit = true;
        memset(F, 0, sizeof(F));
        double A[201][201];
        memset(A, 0, sizeof(A));
        F[0] = A[0][0] = 0.5;
        for(int b = 1; b <= 200; ++b)
            A[0][b] = 1.0;
        for (int a = 1; a <= 200; ++a)
        {            
            for (int b = 1; b <= 200; ++b)
                A[a][b] = 0.25 * (A[max(0, a - 4)][b] + A[max(0, a - 3)][b - 1]
                    + A[max(0, a - 2)][max(0, b - 2)] + A[a - 1][max(0, b - 3)]);
            F[a] = A[a][a];
        }
    }
}
class Solution {
public:
    double soupServings(int n) {
        init();
        if (n > 5'000)
            return 1.0;
        return F[(n + 24) / 25];
    }
};