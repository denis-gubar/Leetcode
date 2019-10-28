class Solution {
public:
	vector<vector<int>> highFive(vector<vector<int>>& items) {
		sort(items.begin(), items.end(),
			[](vector<int> const& a, vector<int> const& b)
		{
			if (a[0] == b[0])
				return a[1] > b[1];
			return a[0] < b[0];
		});
		vector<vector<int>> A;
		A.push_back(items[0]);
		for (int i = 1; i < items.size(); ++i)
		{
			if (items[i][0] != items[i - 1][0])
				A.push_back(items[i]);
			else
				A.back().push_back(items[i][1]);
		}
		vector<vector<int>> result;
		for (vector<int> const& a : A)
		{
			int score = 0;
			for (int i = 1; i <= 5; ++i)
				score += a[i];
			result.push_back({ a[0], score / 5 });
		}
		return result;
	}
};