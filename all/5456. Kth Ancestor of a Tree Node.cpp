class TreeAncestor {
public:
	TreeAncestor(int n, vector<int>& parent) : P(vector<vector<int>>(n)) {
		for (int i = 0; i < n; ++i)
		{
			if (parent[i] != -1)
				P[i].push_back(parent[i]);
		}
		bool changed = true;
		int k = 1;
		while (changed)
		{
			changed = false;
			for (int i = 0; i < n; ++i)
				if (P[i].size() >= k && P[P[i][k - 1]].size() >= k)
				{
					changed = true;
					P[i].push_back(P[P[i][k - 1]][k - 1]);
				}
			++k;
		}
	}

	int getKthAncestor(int node, int k) {
		int result = node;
		int level = 0;
		while (k)
		{
			if (k % 2 == 1)
            {
				if (P[result].size() <= level)
					return -1;
				else
					result = P[result][level];
            }
			k /= 2;
			++level;
		}
        return result;
	}
	vector<vector<int>> P;
};
/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */