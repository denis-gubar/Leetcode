class Solution {
public:
	int convert(const vector<int>& A)
	{
		int result = 0;
		for (int i = 0; i < 8; ++i)
			result |= A[i] << i;
		return result;
	}
	vector<int> next(const vector<int>& cells)
	{
		vector<int> result(8);
		for (int i = 1; i < 7; ++i)
			if (cells[i - 1] == cells[i + 1])
				result[i] = 1;
		return result;
	}
	vector<int> prisonAfterNDays(vector<int>& cells, int N) {
		vector<int> lastVisit(256, -1);
		lastVisit[convert(cells)] = 0;
		for (int i = 1; i <= N; ++i)
		{
			cells = next(cells);
			int key = convert(cells);
			if (lastVisit[key] < 0)
				lastVisit[key] = i;
			else
			{
				int period = i - lastVisit[key];
				int delta = (N - i) % period;
				for (int i = 0; i < delta; ++i)
					cells = next(cells);
				break;
			}
		}
		return cells;
	}
};