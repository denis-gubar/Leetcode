struct UnionFind
{
	vector<int> id;
	vector<int> sz;

	UnionFind(int N) : id(vector<int>(N)), sz(vector<int>(N, 1))
	{
		for (int i = 0; i < N; ++i)
			id[i] = i;
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
		UnionFind unionFind(N);
		vector<char> isPrime(100001, 1);
		isPrime[1] = isPrime[0] = 0;
		for (int i = 2; i * i < 100001; ++i)
			if (isPrime[i])
				for (int k = i * i; k < 100001; k += i)
					isPrime[k] = 0;
		vector<int> primes;
		for (int i = 2; i < 100001; ++i)
			if (isPrime[i])
				primes.push_back(i);
		vector<vector<int>> M(10000);
		for (int i = 0; i < N; ++i)
		{
			int a = A[i];
			for (int p = 0; a > 1; ++p)
			{
				if (a % primes[p] == 0)
				{
					M[p].push_back(i);
					do
					{
						a /= primes[p];
					} while (a % primes[p] == 0);
				}
			}
		}
		for (int i = 0; i < 10000; ++i)
			if (M[i].size() > 1)
				for (int j = 1; j < M[i].size(); ++j)
					if (!unionFind.find(M[i][0], M[i][j]))
						unionFind.unite(M[i][0], M[i][j]);
		return *max_element(unionFind.sz.begin(), unionFind.sz.end());
	}
};