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
	vector<string> split(const string& s, char delimeter = ' ')
	{
		vector<string> result;
		istringstream ss(s);
		for (string token; !ss.eof(); )
		{
			getline(ss, token, delimeter);
			result.push_back(token);
		}
		return result;
	}
public:
	vector<string> generateSentences(vector<vector<string>>& synonyms, string text) {
		if (text.empty()) return {};
		vector<string> S = split(text);
		int g = 0;
		map<string, int> G;
		vector<string> inv;
		for (int i = 0; i < synonyms.size(); ++i)
			for (int j = 0; j < synonyms[i].size(); ++j)
				if (G.find(synonyms[i][j]) == G.end())
					G[synonyms[i][j]] = g, ++g, inv.push_back(synonyms[i][j]);
		UnionFind unionFind(g);
		for (int i = 0; i < synonyms.size(); ++i)
			for (int j = 1; j < synonyms[i].size(); ++j)
				unionFind.checkedUnite(G[synonyms[i][j - 1]], G[synonyms[i][j]]);
		map<int, vector<string>> groups;
		for (int i = 0; i < g; ++i)
			groups[unionFind.root(i)].push_back(inv[i]);
		vector<string> result;
		for (int i = 0; i < S.size(); ++i)
		{
			vector<string> next;
			string t = S[i];
			vector<string> list{ t };
			if (G.find(t) != G.end())
				list = groups[unionFind.root(G[t])];
			if (i == 0)
				for (string const& l : list)
					next.push_back(l);
			else
				for (string const& r : result)
					for (string const& l : list)
						next.push_back(r + ' ' + l);
			result = move(next);
		}
        sort(result.begin(), result.end());
		return result;
	}
};