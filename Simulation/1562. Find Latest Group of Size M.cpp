class Solution {
public:
	struct UnionFind
	{
		vector<int> id;
		vector<int> sz;
		vector<int> groups;
		int m;

		UnionFind(int N, int m) : m(m), id(vector<int>(N)), sz(vector<int>(N, 1)), groups(N + 1)
		{
			for (int i = 0; i < N; ++i)
				id[i] = i;
			groups[1] = N;
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
			--groups[sz[i]];
			--groups[sz[j]];
			if (sz[i] < sz[j])
			{
				id[i] = j; sz[j] += sz[i];
				++groups[sz[j]];
			}
			else
			{
				id[j] = i; sz[i] += sz[j];
				++groups[sz[i]];
			}
		}
	};
	int findLatestStep(vector<int>& arr, int m) {
		int N = arr.size();
		vector<bool> visited(N);
		int result = -1;
		if (m == 1)
		{
			auto calc = [&visited, N](int x)
			{
				if (x < 0 || x == N || !visited[x]) return -1;
				int neighbors = 0;
				if (x > 0 && visited[x - 1])
					++neighbors;
				if (x < N - 1 && visited[x + 1])
					++neighbors;
				return neighbors;
			};
			int count = 0;
			for (int i = 0; i < N; ++i)
			{
				int x = arr[i] - 1;
				int before = (calc(x - 1) == 0) + (calc(x) == 0) + (calc(x + 1) == 0);
				visited[x] = true;
				int after = (calc(x - 1) == 0) + (calc(x) == 0) + (calc(x + 1) == 0);
				count -= before;
				count += after;
				if (count)
					result = i + 1;
			}
            return result;
		}
		UnionFind unionFind(N, m);
		for (int i = 0; i < N; ++i)
		{
			int x = arr[i] - 1;
			visited[x] = true;
			if (x > 0 && visited[x - 1])
				unionFind.unite(x, x - 1);
			if (x < N - 1 && visited[x + 1])
				unionFind.unite(x, x + 1);
			if (unionFind.groups[m])
				result = i + 1;
		}
		return result;
	}
};