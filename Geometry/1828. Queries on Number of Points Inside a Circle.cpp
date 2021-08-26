class Solution {
public:
	vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
		vector<int> result;
		for (auto const& q : queries)
		{
			int const& x = q[0];
			int const& y = q[1];
			int const& r = q[2];
			int r2 = r * r;
			result.push_back(0);
			for (auto const& p : points)
			{
				int const& X = p[0];
				int const& Y = p[1];
				if ((x - X) * (x - X) + (y - Y) * (y - Y) <= r2)
					++result.back();
			}
		}
		return result;
	}
};