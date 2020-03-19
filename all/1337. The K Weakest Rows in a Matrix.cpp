class Solution {
public:
	vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
		vector<int> result;
		for (int i = 0; i < mat.size(); ++i)
			result.push_back(i);
		sort(result.begin(), result.end(), [&mat](int a, int b)
			{
				int A = accumulate(mat[a].begin(), mat[a].end(), 0);
				int B = accumulate(mat[b].begin(), mat[b].end(), 0);
				if (A != B)
					return A < B;
				return a < b;
			} );
		result.resize(k);
		return result;
	}
};