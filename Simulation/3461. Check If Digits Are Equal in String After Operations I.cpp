static int F[6][6];
static int D[5][2];
static bool isInit = false;
static int calc(int n, int k)
{
    if (k < 0 || k > n)
        return 0;
    if (n == k || k == 0)
        return 1;
    if (F[n][k] == -1)
        F[n][k] = calc(n - 1, k - 1) + calc(n - 1, k);
    return F[n][k];
}
static void init()
{
    if (!isInit)
    {
        isInit = true;
        memset(F, -1, sizeof(F));
        for (int i = 0; i < 10; ++i)
            D[i % 5][i % 2] = i;
    }
}
class Solution {
public:
    vector<int> F2(int x)
    {
        if (x == 0)
            return { 0 };
        vector<int> result;
        while (x > 0)
        {
            result.push_back(x % 2);
            x /= 2;
        }
        return result;
    }
    vector<int> F5(int x)
    {
        if (x == 0)
            return { 0 };
        vector<int> result;
        while (x > 0)
        {
            result.push_back(x % 5);
            x /= 5;
        }
        return result;
    }
    int F(int N, int K)
    {
        vector<int> N2 = F2(N);
        vector<int> K2 = F2(K);
        int const M2 = N2.size();
        K2.resize(M2, 0);
        int total2 = 1;
        for (int i = 0; i < M2; ++i)
            total2 = total2 * calc(N2[i], K2[i]) % 2;
        vector<int> N5 = F5(N);
        vector<int> K5 = F5(K);
        int const M5 = N5.size();
        K5.resize(M5, 0);
        int total5 = 1;
        for (int i = 0; i < M5; ++i)
            total5 = total5 * calc(N5[i], K5[i]) % 5;
        return D[total5][total2];
    }
    bool hasSameDigits(string s) {
        init();
        int const N = s.size();
        int A = 0, B = 0;
        for (int i = 0; i < N - 1; ++i)
        {
            int x = F(N - 2, i);
            A = (A + x * (s[i] - '0')) % 10;
            B = (B + x * (s[i + 1] - '0')) % 10;
        }
        return A == B;
    }
};
