class Solution {
public:
	bool validMountainArray(vector<int>& A) {
		if (A.size() < 3) return false;
		if (unique(A.begin(), A.end()) != A.end())
			return false;
		auto it = max_element(A.begin(), A.end());
		if (!is_sorted(A.begin(), next(it),
			[](int a, int b)
			{
				return a < b;
			}) || next(it) == A.end() || it == A.begin() ||
				!is_sorted(next(it), A.end(),
					[](int a, int b)
					{
						return a > b;
					}))
			return false;
					return true;
	}
};