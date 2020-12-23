class Solution {
public:
	vector<int> frequencySort(vector<int>& nums) {
		vector<int> result;
		map<int, int> M;
		for (int n : nums)
			++M[n];
		vector<pair<int, int>> A;
		for (auto m : M)
			A.push_back({ m.second, -m.first });
		sort(A.begin(), A.end());
		for (int i = 0; i < A.size(); ++i)
			for(int j = 0; j < A[i].first; ++j)
				result.push_back(-A[i].second);
		return result;
	}
};