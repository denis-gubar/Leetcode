int static F[100'001];
int static primeCount = 0;
bool static isInit = false;
static void init()
{
    if (!isInit)
    {
        isInit = true;
        int primes[100'001];
        vector<bool> isPrime(100'001, 1);
        isPrime[1] = isPrime[0] = 0;
        for (int i = 2; i * i < 100'001; ++i)
            if (isPrime[i])
                for (int k = i * i; k < 100'001; k += i)
                    isPrime[k] = 0;
        for (int i = 2; i < 100'001; ++i)
            if (isPrime[i])
                primes[primeCount] = i, ++primeCount;
        memset(F, 0, sizeof(F));
        for (int i = 1; i < 100'001; ++i)
        {
            int x = i;
            for (int k = 0; x > 1; ++k)
                if (x % primes[k] == 0)
                {
                    ++F[i];
                    while (x % primes[k] == 0)
                        x /= primes[k];
                }
        }
    }
}
class Solution {
public:
    int const MOD = 1'000'000'007;
    struct Data
    {
        int value;
        int pos;
    };
    int power(int x, int n)
    {
        if (n == 1)
            return x;
        long long result = x;
        long long extra = 1;
        while (n > 1)
        {
            if (n % 2)
            {
                extra *= result;
                extra %= MOD;
            }
            result *= result;
            result %= MOD;
            n /= 2;
        }
        return result * extra % MOD;
    }
    int maximumScore(vector<int>& nums, int k) {
        init();
        int N = nums.size();
        auto cmp = [](Data a, Data b)
        {
            if (a.value != b.value)
                return a.value < b.value;
            return a.pos > b.pos;
        };
        priority_queue<Data, vector<Data>, decltype(cmp)> PQ(cmp);
        for (int i = 0; i < N; ++i)
            PQ.push({ nums[i], i });
        vector<pair<int, int>> P(N);
        for (int i = 0; i < N; ++i)
            P[i] = { -F[nums[i]], i };
        sort(P.begin(), P.end());
        set<int> S;
        S.insert(-1);
        S.insert(N);
        vector<int> L(N), R(N, N - 1);
        for (int i = 0; i < N; )
        {
            int j = i;
            while (j < N && P[i].first == P[j].first)
            {
                ++j;
            }
            for (int z = i; z < j; ++z)
            {
                int pos = P[z].second;
                auto it = S.lower_bound(pos);
                R[pos] = *it - 1;
                L[pos] = *(prev(it)) + 1;
                S.insert(P[z].second);
            }
            i = j;
        }
        long long result = 1;
        for (int i = 0; !PQ.empty() && i < k; )
        {
            Data d = PQ.top(); PQ.pop();
            int left = L[d.pos], right = R[d.pos];
            long long x = 1LL * (d.pos - left + 1) * (right - d.pos + 1);
            int delta = min<long long>(k - i, x);
            i += delta;
            result = result * power(d.value, delta) % MOD;
        }
        return result;
    }
};
