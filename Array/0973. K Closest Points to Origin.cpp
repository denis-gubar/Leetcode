class Solution {
public:
	static int calc(const vector<int>& a)
	{
		return a[0] * a[0] + a[1] * a[1];
	}
	vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
		vector<vector<int>> result(points);
		nth_element(result.begin(), result.begin() + (K - 1), result.end(),
			[](const vector<int>& a, const vector<int>& b)
		{
			return calc(a) < calc(b);
		});
		result.resize(K);
		return result;
	}
};