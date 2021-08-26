class Solution {
public:
	int minSwaps(vector<vector<int>>& grid) {
		int N = grid.size();
		int result = 0;
		vector<int>	A(N, -1);
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				if (grid[i][j])
					A[i] = j;
		for(int i = 0; i < N; ++i)
			if (A[i] > i)
			{
				bool found = false;
				for (int j = i + 1; j < N; ++j)
					if (A[j] <= i)
					{
						found = true;
						rotate(A.begin() + i, A.begin() + j, A.begin() + j + 1);
						result += j - i;
						break;
					}
				if (!found)
					return -1;
			}
		return result;
	}
};