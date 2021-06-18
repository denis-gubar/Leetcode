class Solution {
public:
	bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
		vector<vector<int>> A;
		for (int i = 0; i < triplets.size(); ++i)
		{
			int count = 0;
			for (int j = 0; j < 3; ++j)
				if (triplets[i][j] <= target[j])
					++count;
			if (count == 3)
				A.push_back(triplets[i]);
		}
		vector<bool> visited(3);
		for (vector<int> const& X : A)
			for (int j = 0; j < 3; ++j)
				if (X[j] == target[j])
					visited[j] = true;
		for (bool flag : visited)
			if (!flag)
				return false;
		return true;
	}
};