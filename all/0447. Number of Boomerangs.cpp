class Solution {
public:
	int numberOfBoomerangs(vector<vector<int>>& points) {
		int N = points.size();
		int result = 0;
		auto calc = [&points](int x, int y)
		{
			return (points[x][0] - points[y][0]) * (points[x][0] - points[y][0]) +
				(points[x][1] - points[y][1]) * (points[x][1] - points[y][1]);
		};
		unordered_map<int, int> M;
		for (int i = 0; i < N; ++i)
		{
			M.clear();
			for (int j = 0; j < N; ++j)
				if (i != j)
					++M[{calc(i, j)}];
			for (auto p : M)
				result += (p.second - 1) * p.second;
		}
		return result;
	}
};