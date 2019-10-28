class Solution {
public:
	int maxDistance(vector<vector<int>>& arrays) {
		int result = 0;
		int a = arrays[0][0], b = arrays[0].back();
		for (int i = 1; i < arrays.size(); ++i)
		{
			result = max({ result, abs(arrays[i][0] - b), abs(arrays[i].back() - a) });
			a = min(a, arrays[i][0]);
			b = max(b, arrays[i].back());
		}
		return result;
	}
};