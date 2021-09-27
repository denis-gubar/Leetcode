class Solution {
public:
	int movesToChessboard(vector<vector<int>>& board) {
		int N = board.size();
		int result = N + 1;
		for (int parity = 0; parity < 2; ++parity)
		{
			vector<int> A(N);
			iota(A.begin(), A.end(), 0);
			vector<vector<int>> columnWrongPositions(2);
			for (int j = 0; j < N; ++j)
				if ((parity + board[0][j] + j) % 2 != 0)
					columnWrongPositions[board[0][j]].push_back(j);
			if (columnWrongPositions[0].size() != columnWrongPositions[1].size())
				continue;
			int current = columnWrongPositions[0].size();
			for (int j = 0; j < columnWrongPositions[0].size(); ++j)
				swap(A[columnWrongPositions[0][j]], A[columnWrongPositions[1][j]]);
			for (int p = 0; p < 2; ++p)
			{
				vector<vector<int>> rowWrongPositions(2);
				int delta = 0;
				for (int i = 0; i < N; ++i)
				{
					int okCount = 0;
					{
						for (int j = 0; j < N; ++j)
							okCount += (p + parity + board[i][A[j]] + i + j) % 2 == 0;
						if (okCount == 0)
							rowWrongPositions[i % 2].push_back(i);
					}
					if (okCount % N != 0)
					{
						delta = N + 1;
						break;
					}
				}
				if (rowWrongPositions[0].size() != rowWrongPositions[1].size())
					continue;
				delta = max<int>(delta, rowWrongPositions[0].size());
				result = min(result, current + delta);
			}
		}
		if (result > N)
			result = -1;
		return result;
	}
};