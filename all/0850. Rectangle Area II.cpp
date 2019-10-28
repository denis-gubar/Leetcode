class Solution {
public:
	static const int MOD = 1000000007;
	int rectangleArea(vector<vector<int>>& rectangles) {
		long long result = 0, N = rectangles.size();
		set<int> X, Y;
		for (int i = 0; i < N; ++i)
		{
			X.insert(rectangles[i][0]);
			Y.insert(rectangles[i][1]);
			X.insert(rectangles[i][2]);
			Y.insert(rectangles[i][3]);
		}
		map<int, int> MX, MY;
        vector<int> SX, SY;
		int kx = 0;
		for (int x : X)
		{
			MX[x] = kx;
			++kx;
            SX.push_back(x);            
		}
		int ky = 0;
		for (int y : Y)
		{
			MY[y] = ky;
			++ky;
            SY.push_back(y);
		}
		vector<vector<long long>> grid(kx, vector<long long>(ky));
		for (int i = 0; i < N; ++i)
		{
			for (int x = MX[rectangles[i][0]]; x < MX[rectangles[i][2]]; ++x)
				for (int y = MY[rectangles[i][1]]; y < MY[rectangles[i][3]]; ++y)
					if (!grid[x][y])
						grid[x][y] = 1LL * (*X.upper_bound(SX[x]) - SX[x]) * (*Y.upper_bound(SY[y]) - SY[y]);
		}
		for (const vector<long long>& g : grid)
			for (long long i : g)
				result += i;
		return result % MOD;
	}
};