class Solution {
public:
	int findCenter(vector<vector<int>>& edges) {
		int N = edges.size() + 1;
		unordered_map<int, int> M;
		for (int i = 0; i < 2; ++i)
		{
			int const& V = edges[i][0];
			int const& U = edges[i][1];
			++M[V];
			++M[U];
		}
		for (auto p : M)
			if (p.second == 2)
				return p.first;
		return -1;
	}
};