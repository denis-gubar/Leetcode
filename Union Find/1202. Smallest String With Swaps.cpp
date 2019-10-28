class Solution {
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
		void checkedUnite(int p, int q)
		{
			if (!find(p, q))
				unite(p, q);
		}
	};
public:
	string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
		int N = s.size();
		UnionFind unionFind(N);
		for (vector<int> const& pair : pairs)
			unionFind.checkedUnite(pair[0], pair[1]);
		vector<vector<int>> cycles(N);
		for (int i = 0; i < N; ++i)
		{
			int v = unionFind.root(i);
			cycles[v].push_back(i);
		}
		for (vector<int>& cycle : cycles)
			if (cycle.size() > 1)
			{
				sort(cycle.begin(), cycle.end());
				string t;
				for (int i : cycle)
					t += s[i];
				sort(t.begin(), t.end());
				for (int i = 0; i < t.size(); ++i)
					s[cycle[i]] = t[i];
			}
		return s;
	}
};