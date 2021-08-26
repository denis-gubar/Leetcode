class Solution {
public:
	vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
		vector<int> result;
		map<string, int> M;
		int k = 0;
		vector<vector<int>> Z;
		for (vector<string> const& F : favoriteCompanies)
		{
			Z.push_back({});
			for (string const& w : F)
			{
				if (M.find(w) == M.end())
					M[w] = k, ++k;
				Z.back().push_back(M[w]);
			}
		}
		for (vector<int>& z : Z)
			sort(z.begin(), z.end());
		for (int i = 0; i < Z.size(); ++i)
		{
			vector<int> const& A = Z[i];
			bool isOk = true;
			for (int j = 0; isOk && j < Z.size(); ++j)
				if (i != j)
				{
					vector<int> const& B = Z[j];
					vector<int> C;
					set_difference(A.begin(), A.end(), B.begin(), B.end(), back_inserter(C));
					isOk = !C.empty();
				}
			if (isOk)
				result.push_back(i);
		}
		return result;
	}
};