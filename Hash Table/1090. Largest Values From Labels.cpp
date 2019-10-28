class Solution {
public:
	int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
		vector<vector<int>> M(20001);
		for (int i = 0; i < values.size(); ++i)
			M[labels[i]].push_back(values[i]);
		vector<int> A;
		for (vector<int>& m : M)
			if (!m.empty())
			{
				sort(m.begin(), m.end(), greater<int>());
				if (m.size() > use_limit)
					m.resize(use_limit);
				copy(m.begin(), m.end(), back_inserter(A));
			}
		sort(A.begin(), A.end(), greater<int>());
		int result = 0;
		for (int i = 0; i < A.size() && i < num_wanted; ++i)
			result += A[i];
		return result;
	}
};