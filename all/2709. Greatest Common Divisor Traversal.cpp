static int primes[10'000];
static int P[100'001];
static bool isInit = false;
static vector<bool> isPrime(100'001, 1);
static int divs[100'001][20];
static void init()
{
    if (!isInit)
    {
        isInit = true;
        memset(primes, 0, sizeof(primes));
        memset(P, 0, sizeof(P));
        memset(divs, 0, sizeof(divs));
        isPrime[1] = isPrime[0] = 0;
        for (int i = 2; i * i < 100'001; ++i)
            if (isPrime[i])
                for (int k = i * i; k < 100'001; k += i)
                    isPrime[k] = 0;
        for (int k = 2; k < 100'001; ++k)
        {
            int x = k;
            for(int i = 2; i * i <= x; ++i)
                if (x % i == 0)
                {
                    int pos = ++divs[k][0];
                    divs[k][pos] = i;
                    while (x % i == 0)
                        x /= i;
                }
            if (x > 1)
            {
                int pos = ++divs[k][0];
                divs[k][pos] = x;
            }
        }
        int primeCount = 0;
        for (int i = 2; i < 100'001; ++i)
            if (isPrime[i])
            {
                primes[primeCount] = i;
                P[i] = primeCount;
                ++primeCount;
            }
    }
}
class Solution {
public:
    struct UnionFind
    {
        vector<int> id, groupSize;
        UnionFind(int N) : id(vector<int>(N)), groupSize(vector<int>(N, 1))
        {
            iota(id.begin(), id.end(), 0);
        }
        int root(int x)
        {
            while (x != id[x])
                x = id[x] = id[id[x]];
            return x;
        }
        bool find(int p, int q)
        {
            return root(p) == root(q);
        }
        void unite(int p, int q)
        {
            p = root(p), q = root(q);
            if (groupSize[p] < groupSize[q])
                id[p] = q, groupSize[q] += groupSize[p];
            else
                id[q] = p, groupSize[p] += groupSize[q];
        }
        void checkedUnite(int p, int q)
        {
            if (!find(p, q))
                unite(p, q);
        }
    };
    bool canTraverseAllPairs(vector<int>& nums) {
        init();
        int N = nums.size();
        vector<int> M(100'001);
        for (int x : nums)
            ++M[x];
        if (M[1] > 0)
            return N == 1;
        vector<bool> visited(10'001);
        UnionFind UF(10'001);
        for (int x : nums)
            for (int i = 1; i <= divs[x][0]; ++i)
            {
                int a = P[divs[x][i]];
                visited[a] = true;
                UF.checkedUnite(P[divs[x][1]], a);
            }
        int uniquePrimes = accumulate(visited.begin(), visited.end(), 0);
        return UF.groupSize[UF.root(P[divs[nums[0]][1]])] == uniquePrimes;
    }
};
