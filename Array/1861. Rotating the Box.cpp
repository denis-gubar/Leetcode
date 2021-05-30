class Solution {
public:
	vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
		int N = box.size(), M = box[0].size();
		vector<vector<char>> result(M, vector<char>(N, '+'));
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
				result[j][i] = box[N - i - 1][j];
		for (int i = 0; i < N; ++i)
		{
			int last = M - 1;
			for (int j = M - 1; j >= 0; --j)
			{
				if (result[j][i] == '*')
					last = j - 1;
				if (result[j][i] == '#')
				{
					result[j][i] = '.';
					result[last][i] = '#';
					--last;
				}
			}
		}
		return result;
	}
};