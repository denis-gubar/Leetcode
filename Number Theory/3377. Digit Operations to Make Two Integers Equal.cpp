static bool isInit = false;
static vector<bool> isPrime(10'000, true);
static void init()
{
    if (!isInit)
    {
        isInit = true;
        isPrime[1] = isPrime[0] = false;
        for (int i = 2; i * i < 10'000; ++i)
            if (isPrime[i])
                for (int k = i * i; k < 10'000; k += i)
                    isPrime[k] = false;
    }
}
static int F[10'000];
class Solution {
public:
    int minOperations(int N, int M) {
        init();
        array const P10{ 1, 10, 100, 1'000 };
        int length = to_string(N).size();
        memset(F, -1, sizeof(F));
        if (isPrime[N] || isPrime[M])
            return -1;
        F[N] = N;
        set<pair<int, int>> S;
        S.insert({ N, N });
        vector<int> A;
        A.reserve(4);
        while (!S.empty())
        {
            pair<int, int> const P = *S.begin();
            S.erase(S.begin());
            int const& T = P.first;
            int const& N = P.second;
            if (N == M)
                break;
            string s = to_string(N);            
            A.clear();
            while (!s.empty())
                A.push_back(s.back() - '0'), s.pop_back();
            for (int i = 0; i < length; ++i)
            {
                int const& d = A[i];
                if (d < 9)
                {
                    int NN = N + P10[i];
                    if (!isPrime[NN] && F[NN] == -1)
                    {
                        S.insert({ F[N] + NN, NN });
                        F[NN] = F[N] + NN;
                    }
                }
                if (d > 0 && i < length - 1 || d > 1)
                {
                    int NN = N - P10[i];
                    if (!isPrime[NN] && F[NN] == -1)
                    {
                        S.insert({ F[N] + NN, NN });
                        F[NN] = F[N] + NN;
                    }
                }
            }
        }
        return F[M];
    }
};
