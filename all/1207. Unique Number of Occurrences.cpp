class Solution {
public:
	bool uniqueOccurrences(vector<int>& arr) {
		unordered_map<int, int> M;
		for (int a : arr)
			++M[a];
		vector<int> A;
        A.reserve(M.size());
		for (auto m : M)
			A.push_back(m.second);
		int count = A.size();
		sort(A.begin(), A.end());
		A.resize(unique(A.begin(), A.end()) - A.begin());
		int distinctCount = A.size();
		return count == distinctCount;
	}
};