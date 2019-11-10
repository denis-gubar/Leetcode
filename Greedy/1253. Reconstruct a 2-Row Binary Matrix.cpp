class Solution {
public:
	vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
		int N = colsum.size();
		vector<vector<int>> result(2, vector<int>(N));
		vector<int> onesCount{ 0, 0 };
		for (int i = 0; i < N; ++i)
			if (colsum[i] == 2)
			{
				++onesCount[0], ++onesCount[1];
				result[0][i] = result[1][i] = 1;
			}
		for (int i = 0; i < N; ++i)
			if (colsum[i] == 1)
			{
				int row = 0;
				if (onesCount[0] == upper)
					row = 1;
				++onesCount[row];
				result[row][i] = 1;
			}
		if (onesCount[1] != lower)
			return {};
		return result;
	}
};