class Solution {
public:
	bool calc(vector<int>& A, vector<int> const& quantity, int N, int i)
	{
		if (i == quantity.size())
			return true;
		for(int j = 0; j < N; ++j)
			if (A[j] >= quantity[i])
			{
				A[j] -= quantity[i];
				if (calc(A, quantity, N, i + 1))
					return true;
				A[j] += quantity[i];
			}
		return false;
	}
	bool canDistribute(vector<int>& nums, vector<int>& quantity) {
		unordered_map<int, int> ind;
		vector<int> A;
		for (int n : nums)
			if (ind.find(n) == ind.end())
			{
				ind[n] = A.size();
				A.push_back(1);
			}
			else
			{
				++A[ind[n]];
			}
		sort(A.begin(), A.end());
		reverse(A.begin(), A.end());
		sort(quantity.begin(), quantity.end());
		reverse(quantity.begin(), quantity.end());
		return calc(A, quantity, A.size(), 0);
	}
};