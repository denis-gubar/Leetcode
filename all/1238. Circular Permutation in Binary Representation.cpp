class Solution {
public:
	vector<int> circularPermutation(int n, int start) {
		vector<int> result(1 << n);
		result[1] = 1;
		for (int k = 1; k < n; ++k)
			for (int x = 0; x < (1 << k); ++x)
				result[(2 << k) - x - 1] = result[x] | (1 << k);
		auto it = find(result.begin(), result.end(), start);
		rotate(result.begin(), it, result.end());
		return result;
	}
};