class Solution {
public:
	int numEquivDominoPairs(vector<vector<int>>& dominoes) {
		map<vector<int>, int> M;
		for (auto& domino : dominoes)
		{
			sort(domino.begin(), domino.end());
			++M[domino];
		}
		int result = 0;
		for (auto m : M)
			result += m.second * (m.second - 1) / 2;
		return result;
	}
};
