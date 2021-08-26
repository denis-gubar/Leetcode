class Solution {
public:
	int mincostTickets(vector<int>& days, vector<int>& costs) {
		vector<int> A(366);
		for (int d : days)
			++A[d];
		vector<int> M(400, 1'000'000);
		M[0] = 0;
		for(int i = 1; i < 366; ++i)
			if (A[i])
			{
				for (int j = 0; j < 1; ++j)
					M[i + j] = min(M[i + j], M[i - 1] + costs[0]);
				for (int j = 0; j < 7; ++j)
					M[i + j] = min(M[i + j], M[i - 1] + costs[1]);
				for (int j = 0; j < 30; ++j)
					M[i + j] = min(M[i + j], M[i - 1] + costs[2]);
			}
			else
			{
				M[i] = min(M[i], M[i - 1]);
			}
		return M[365];
	}
};