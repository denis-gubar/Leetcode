class Solution {
public:
	vector<vector<int>> children;
	vector<unordered_map<int, int>> F;
    vector<int> parent;
    string s;
	int calc(int V, int U)
	{
		int& result = F[V][U];
		if (result < 0)
		{
			if (s[V] == s[U])
				result = 0;
			else
			{
				result = 1;
				for (int T : children[U])
					result = max(result, 1 + calc(U, T));
			}
		}
		return result;
	};
    int longestPath(vector<int>& parent, string s) {
        this->parent = parent;
        this->s = s;
        int result = 1;
        int N = s.size();
        children = vector<vector<int>>(N);
        F = vector<unordered_map<int, int>>(N);
        for (int i = 1; i < N; ++i)
        {
            children[parent[i]].push_back(i);
            F[parent[i]][i] = -1;
        }        
        for (int V = 0; V < N; ++V)
        {
            vector<int> A{ 0, 0 };
            for (int U : children[V])
                A.push_back(calc(V, U));
            sort(A.begin(), A.end(), greater<int>{});
            result = max(result, 1 + A[0] + A[1]);
        }
        return result;
    }
};
