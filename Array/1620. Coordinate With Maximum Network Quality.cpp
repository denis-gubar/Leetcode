class Solution {
public:
	double dist(int x1, int y1, int x2, int y2)
	{
		double result = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
		return sqrt(result);
	}
	vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
		vector<int>	result{ -1, -1 };
		int best = -1;
		int N = towers.size();
		for(int x = 0; x <= 50; ++x)
			for (int y = 0; y <= 50; ++y)
			{
				int quality = 0;
				for (int i = 0; i < N; ++i)
				{
					int const& tx = towers[i][0];
					int const& ty = towers[i][1];
					int const& tq = towers[i][2];
					double L = dist(x, y, tx, ty);
					if (L - 1e-10 <= radius)
						quality += tq / (1 + L);					
				}
				if (quality > best)
					result[0] = x, result[1] = y, best = quality;
			}
		return result;
	}
};