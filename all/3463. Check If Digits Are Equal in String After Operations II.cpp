static int C[6][6];
static int D[5][2];
static int N2[20];
static int N5[10];
static int K2[20];
static int K5[10];
static bool isInit = false;
static int calc(int n, int k)
{
    if (k < 0 || k > n)
        return C[n][k] = 0;
    if (n == k || k == 0)
        return C[n][k] = 1;
    if (C[n][k] == -1)
        C[n][k] = calc(n - 1, k - 1) + calc(n - 1, k);
    return C[n][k];
}
static void init()
{
    if (!isInit)
    {
        isInit = true;
        memset(C, -1, sizeof(C));
        for (int i = 0; i < 10; ++i)
            D[i % 5][i % 2] = i;
        for (int i = 0; i <= 5; ++i)
            for (int j = 0; j <= 5; ++j)
                calc(i, j);
    }
}
class Solution {
public:
    void F2(int x)
    {
        for (int i = 0; i < 20; ++i)
            K2[i] = x % 2, x /= 2;
    }
    void F5(int x)
    {
        for (int i = 0; i < 10; ++i)
            K5[i] = x % 5, x /= 5;
    }
    int F(int N, int K)
    {
        F2(K);
        int total2 = 1;
        for (int i = 0; i < 20 && total2 > 0; ++i)
            total2 = total2 * C[N2[i]][K2[i]] % 2;
        F5(K);
        int total5 = 1;
        for (int i = 0; i < 10 && total5 > 0; ++i)
            total5 = total5 * C[N5[i]][K5[i]] % 5;
        return D[total5][total2];
    }
    bool hasSameDigits(string s) {
        init();
        int const N = s.size();
        int A = 0, B = 0;
        F2(N - 2), F5(N - 2);
        memcpy(N2, K2, sizeof(K2));
        memcpy(N5, K5, sizeof(K5));
        for (int i = 0; i < N - 1; ++i)
        {
            int x = F(N - 2, i);
            A = (A + x * (s[i] - '0')) % 10;
            B = (B + x * (s[i + 1] - '0')) % 10;
        }
        return A == B;
    }
};
