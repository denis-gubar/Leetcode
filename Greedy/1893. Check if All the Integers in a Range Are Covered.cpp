class Solution {
public:
	bool isCovered(vector<vector<int>>& ranges, int left, int right) {
		vector<bool> A(51);
		for (vector<int> const& r : ranges)
			for (int x = r[0]; x <= r[1]; ++x)
				A[x] = true;
		for(int x = left; x <= right; ++x)
			if (!A[x])
				return false;
		return true;
	}
};