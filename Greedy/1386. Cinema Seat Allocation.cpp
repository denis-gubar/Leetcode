class Solution {
public:
	int fill(int start, int end)
	{
		int result = 0;
		if (start < 2 && end > 5)
		{
			++result;
			start = 5;
		}
		if (start < 4 && end > 7)
		{
			++result;
			start = 7;
		}
		if (start < 6 && end > 9)
			++result;
		return result;
	}
	int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
		int result = 0, A = reservedSeats.size();
		sort(reservedSeats.begin(), reservedSeats.end());
		int row = 1, col = 0;
		for (int pos = 0; pos < A; ++pos)
		{
			if (row < reservedSeats[pos][0])
			{
				result += fill(col, 10);
				result += 2 * (reservedSeats[pos][0] - row - 1);
				row = reservedSeats[pos][0];
				col = 0;
			}
			result += fill(col, reservedSeats[pos][1]);
			col = reservedSeats[pos][1];
		}
		if (row < n)
		{
			result += fill(col, 10);
			result += 2 * (n - row - 1);
			col = 0;
		}
		result += fill(col, 10);
		return result;
	}
};