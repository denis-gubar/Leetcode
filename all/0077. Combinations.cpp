class Solution {
public:
	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> result;
		vector<int> A(n);
		for (int i = 0; i < k; ++i)
			A[i] = 1;
		reverse(A.begin(), A.end());
		do
		{
			result.push_back({});
			for (int i = 0; i < n; ++i)
				if (A[i])
					result.back().push_back(i + 1);
		} while (next_permutation(A.begin(), A.end()));
		return result;
	}
};