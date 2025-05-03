static int F[334][10][2][2];
static int MOD = 1'000'000'007;
class Solution {
public:
    int calc(string const& B, int base)
    {
        int const N = B.size();
        memset(F, 0, sizeof(F));
        F[0][0][true][true] = 1;
        for (int i = 0; i < N; ++i)
            for (int isB = 0; isB < 2; ++isB)
                for (int isZero = 0; isZero < 2; ++isZero)
                    for (int prev = 0, b = B[i] - '0'; prev < base; ++prev)
                    {
                        int& prevF = F[i][prev][isB][isZero];
                        if (!prevF)
                            continue;
                        for (int d = prev; d < base; ++d)
                        {
                            if (!isB || d <= b)
                            {
                                int& nextF = F[i + 1][d][isB && d == b][isZero && d == 0];
                                nextF += prevF;
                                nextF %= MOD;
                            }
                        }
                    }
        long long result = 0;
        for (int prev = 1; prev < base; ++prev)
            for (int isB = 0; isB < 2; ++isB)
                result += F[N][prev][isB][false];
        return result % MOD;
    }
    string convert(int from, int to, string const& s)
    {
        int const N = s.size();
        int const NO = N * (from / to + 1);
        vector<int> A(NO + 10);
        vector<int> C(NO + 10);
        vector<int> F(N);
        int k = 0;
        for(int i = N - 1, k = 0; i >= 0; --i, ++k)
            F[k] = s[i] - '0';
        A[0] = 1;
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < NO; ++j)
            {
                C[j] += A[j] * F[i];
                int temp = C[j];
                int rem = 0;
                int ip = j;
                do
                {
                    rem = temp / to;
                    C[ip] = temp - rem * to; ip++;
                    C[ip] += rem;
                    temp = C[ip];
                } while (temp >= to);
            }

            for (int j = 0; j < NO; j++)
                A[j] = A[j] * from;
            for (int j = 0; j < NO; j++) 
            {
                int temp = A[j];
                int rem = 0;
                int ip = j;
                do 
                {
                    rem = temp / to;
                    A[ip] = temp - rem * to; ip++;
                    A[ip] += rem;
                    temp = A[ip];
                } while (temp >= to);
            }
        }
        string result;
        bool first = false;
        for (int i = NO; i >= 0; --i)
        {
            if (C[i] != 0)
                first = true;
            if (!first)
                continue;
            result += C[i] + '0';
        }
        if (result.empty())
            return "0";
        return result;
    }
    int countNumbers(string l, string r, int base) {
        int const N = l.size();
        reverse(l.begin(), l.end());
        int i = 0;
        for (; i < N && l[i] == '0'; ++i)
            l[i] = '9';
        --l[i];
        if (l[i] == '0' && i == N - 1)
            l.pop_back();
        reverse(l.begin(), l.end());
        string A = convert(10, base, l);
        string B = convert(10, base, r);
        int result = calc(B, base);
        if (A != "0")
            result -= calc(A, base);
        if (result < 0)
            result += MOD;
        return result;
    }
};
