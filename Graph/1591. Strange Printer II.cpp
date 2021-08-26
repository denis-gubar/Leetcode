class Solution {
public:
	bool isPrintable(vector<vector<int>>& targetGrid) {
		int N = targetGrid.size(), M = targetGrid[0].size();
		vector<int>	U(61, 61), D(61, -1), L(61, 61), R(61, -1);
		vector<vector<int>> grid(N, vector<int>(M));
		vector<vector<long long>> mask(N, vector<long long>(M));
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
			{
				int color = targetGrid[i][j];
				U[color] = min(U[color], i);
				D[color] = max(D[color], i);
				L[color] = min(L[color], j);
				R[color] = max(R[color], j);
			}
		for (int color = 1; color <= 60; ++color)
			if (U[color] != 61)
			{
				for (int x = U[color]; x <= D[color]; ++x)
					for (int y = L[color]; y <= R[color]; ++y)
						mask[x][y] |= 1LL << color;
			}
		vector<int>	A;
        unordered_set<int> visited;
		bool changed = true;
		while (changed)
		{
			changed = false;
			for (int color = 1; color <= 60; ++color)
				if (visited.find(color) == visited.end() && U[color] != 61)
				{                    
					bool flag = true;
					for (int x = U[color]; flag && x <= D[color]; ++x)
						for (int y = L[color]; flag && y <= R[color]; ++y)
							flag = mask[x][y] == (1LL << color) && targetGrid[x][y] == color || mask[x][y] != (1LL << color) && targetGrid[x][y] != color;
					if (flag)
					{
						A.push_back(color);
						changed = true;			
                        visited.insert(color);
                        for (int x = U[color]; x <= D[color]; ++x)
					        for (int y = L[color]; y <= R[color]; ++y)
						        mask[x][y] ^= 1LL << color;
					}
				}
		}
		for (int color : A)
		{
			for (int x = U[color]; x <= D[color]; ++x)
				for (int y = L[color]; y <= R[color]; ++y)
					grid[x][y] = color;
		}
		return targetGrid == grid;
	}
};