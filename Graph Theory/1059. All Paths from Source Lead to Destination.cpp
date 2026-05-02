class Solution {
public:
	enum Colors: char
	{
		White, Grey, Black
	};
	bool calc(vector<vector<int>> const& connectivity, int root, vector<Colors>& F)
	{
		if (F[root] == Black)
			return true;
		if (F[root] == Grey)
			return false;
		if (connectivity[root].empty())
			return false;
		F[root] = Grey;
		for (int next : connectivity[root])
			if (!calc(connectivity, next, F))
				return false;
		F[root] = Black;
    	return true;
	}
	bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {        
		vector<Colors> F(n, White);
		F[destination] = Black;
		vector<vector<int>> connectivity(n);
		for (vector<int> const& e : edges)
			connectivity[e[0]].push_back(e[1]);
		return connectivity[destination].empty() && calc(connectivity, source, F);
	}
};