class Solution {
public:
	int minimizeTheDifference(vector<vector<int>>& mat, int target) {
		int result = 0;
		for (vector<int> const& row : mat)
			result += *min_element(row.begin(), row.end());
		if (result >= target)
			return result - target;
		result = target - result;
		bitset<1600> F;
		F[0] = true;
		for (vector<int> const& row : mat)
		{
			bitset<1600> NF;
			for (int x : row)
				NF |= F << x;
			F = move(NF);
		}
		for (int x = 1599; x >= 0; --x)
			if (F[x])
				result = min(result, abs(target - x));
		return result;
	}
};