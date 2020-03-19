class Solution {
public:
	vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
		vector<vector<int>> result;
		int const& A = toBeRemoved[0];
		int const& B = toBeRemoved[1];
		for (vector<int>const& interval : intervals)
		{
			set<int> S;
			int const& a = interval[0];
			int const& b = interval[1];
			S.insert(A); S.insert(B);
			S.insert(a); S.insert(b);
			map<int, int> M;
			int k = 0;
			vector<int> inv;
			for (int s : S)
			{
				M[s] = k;
				++k;
				inv.push_back(s);
			}
			vector<int> X(k);            
			for (int i = M[a]; i < M[b]; ++i)
				X[i] = 1;
			for (int i = M[A]; i < M[B]; ++i)
				X[i] = 0;
			for (int i = 0; i + 1 < k; ++i)
				if (X[i])
					result.push_back({ inv[i], inv[i + 1] });
		}
		sort(result.begin(), result.end());
		return result;
	}
};
