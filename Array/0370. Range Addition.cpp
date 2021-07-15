class Solution {
public:
	vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
		vector<int>	result(length + 1);
		for (vector<int> const& u : updates)
		{
			int const& L = u[0];
			int const& R = u[1];
			int const& delta = u[2];
			result[L] += delta;
			result[R + 1] -= delta;
		}
		partial_sum(result.begin(), result.end(), result.begin());
		result.pop_back();
		return result;
	}
};