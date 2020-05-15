class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		vector<int> result;
		unordered_map<int, int> M;
		for (int n : nums)
			++M[n];
		vector<pair<int, int>> A;
		for (auto m : M)
			A.push_back({ -m.second, m.first });
        sort(A.begin(), A.end());
		for (int i = 0; i < k && i < A.size(); ++i)
			result.push_back(A[i].second);
		return result;
	}
};