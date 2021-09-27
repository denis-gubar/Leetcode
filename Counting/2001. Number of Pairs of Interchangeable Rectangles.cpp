class Solution {
public:
	long long interchangeableRectangles(vector<vector<int>>& rectangles) {
		long long result = 0;
		map<pair<int, int>, int> M;
		for (vector<int> const& rect : rectangles)
		{
			int const& width = rect[0];
			int const& height = rect[1];
			int k = gcd(width, height);
			++M[{width / k, height / k}];
		}
		for (auto [key, value] : M)
			result += 1LL * value * (value - 1) / 2;
		return result;
	}
};