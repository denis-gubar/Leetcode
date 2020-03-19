class Solution {
public:
	vector<int> luckyNumbers(vector<vector<int>>& matrix) {
		vector<int> result;
		for (int i = 0; i < matrix.size(); ++i)
		{
			int minimum = *min_element(matrix[i].begin(), matrix[i].end());
			for(int j = 0; j < matrix[0].size(); ++j)
				if (matrix[i][j] == minimum)
				{
					int maximum = minimum;
					for (int k = 0; k < matrix.size(); ++k)
						maximum = max(maximum, matrix[k][j]);
					if (maximum == minimum)
						result.push_back(matrix[i][j]);
				}
		}
		return result;
	}
};