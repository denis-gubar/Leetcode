int id[100'001];
int sz[100'001];
int M[100'001];
int primes[10'000];
struct UnionFind
{
    int16_t N;

	UnionFind(int N) : N(N)
	{
        iota(id, id + N, 0);
        fill(sz, sz + N, 1);
	}
	int root(int i)
	{
		while (i != id[i])
		{
			id[i] = id[id[i]];
			i = id[i];
		}
		return i;
	}
	bool find(int p, int q)
	{
		return root(p) == root(q);
	}
	void unite(int p, int q)
	{
		int i = root(p);
		int j = root(q);
		if (sz[i] < sz[j])
		{
			id[i] = j; sz[j] += sz[i];
		}
		else
		{
			id[j] = i; sz[i] += sz[j];
		}
	}
};

class Solution {
public:
	int largestComponentSize(vector<int>& A) {
		int N = A.size();
		UnionFind unionFind(100001);
		vector<bool> isPrime(100001, 1);
		isPrime[1] = isPrime[0] = 0;
		for (int i = 2; i * i < 100001; ++i)
			if (isPrime[i])
				for (int k = i * i; k < 100001; k += i)
					isPrime[k] = 0;
		int primeCount = 0;        
		for (int i = 2; i < 100001; ++i)
			if (isPrime[i])
            {
				primes[primeCount] = i;
                ++primeCount;
            }
		memset(M, -1, sizeof(M));
		for (int i = 0; i < N; ++i)
		{
			int a = A[i];            
			for (int p = 0; a > 1; ++p)
			{
                int x = primes[p];
                if (isPrime[a])
                {
                    if (a * 2 > 100'000)
                        break;
                    x = a;
                }                
				if (a % x == 0)
				{
					if (M[x] != -1)
                    {
                        if (!unionFind.find(M[x], A[i]))
						    unionFind.unite(M[x], A[i]);
                    }
                    M[x] = A[i];
					do
					{
						a /= x;
					} while (a % x == 0);
				}
			}
		}
		return *max_element(sz, sz + sizeof(sz) / sizeof(sz[0]));
	}
};