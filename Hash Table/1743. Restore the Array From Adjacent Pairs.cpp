class Solution {
public:
	vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
		vector<int> result;
		int N = adjacentPairs.size();
		vector<unordered_set<int>> A(200'001);
		for (int i = 0; i < N; ++i)
		{
			int const& V = adjacentPairs[i][0] + 100'000;
			int const& U = adjacentPairs[i][1] + 100'000;
			A[V].insert(U);
			A[U].insert(V);
		}
		int V = 0;
		for(int i = 0; i < 200'001; ++i)
			if (A[i].size() == 1)
			{
				V = i;
				break;
			}
		result.push_back(V);
		while (result.size() <= N)
		{
			V = result.back();
			int U = *A[V].begin();
			A[U].erase(V);
            result.push_back(U);
		}
		for (int& x : result)
			x -= 100'000;
		return result;
	}
};