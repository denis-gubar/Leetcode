class Solution {
public:
	vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
		vector<string> result;
		vector<string> INV;
		int N = recipes.size();
		unordered_map<string, int> M;
		for(string const& s : recipes)
			if (M.find(s) == M.end())
			{
				int k = M.size();
				M[s] = k;
				INV.push_back(s);
			}
		for (string const& s : supplies)
			if (M.find(s) == M.end())
			{
				int k = M.size();
				M[s] = k;
				INV.push_back(s);
			}
		for(int i = 0; i < N; ++i)
			for (string const& s : ingredients[i])
				if (M.find(s) == M.end())
				{
					int k = M.size();
					M[s] = k;
					INV.push_back(s);
				}
		vector<vector<int>> ING(N);
		vector<int> REC(N), SUP;
		for (int i = 0; i < N; ++i)
			REC[i] = M[recipes[i]];
		for (int i = 0; i < supplies.size(); ++i)
			SUP.push_back(M[supplies[i]]);
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < ingredients[i].size(); ++j)
				ING[i].push_back(M[ingredients[i][j]]);
		set<int> S(SUP.begin(), SUP.end());
		set<int> R;
		for (int i = 0; i < N; ++i)
			R.insert(i);
		while (true)
		{
			vector<int> A;
			for (int i : R)
			{
				bool hasAll = true;
				for (int ing : ING[i])
					if (S.find(ing) == S.end())
					{
						hasAll = false;
						break;
					}
				if (hasAll)
				{
					S.insert(REC[i]);
					A.push_back(i);
				}
			}
			for (int i : A)
			{
				R.erase(i);
				result.push_back(INV[REC[i]]);
			}
			if (A.empty())
				break;
		}
		return result;
	}
};