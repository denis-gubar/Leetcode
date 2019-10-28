class Solution {
public:
	bool uniqueOccurrences(vector<int>& arr) {
		map<int, int> M;
		for (int a : arr)
			++M[a];
		vector<int> A;
		for (auto m : M)
			A.push_back(m.second);
		int count = A.size();
		sort(A.begin(), A.end());
		A.erase(unique(A.begin(), A.end()), A.end());
		int distinctCount = A.size();
		return count == distinctCount;
	}
};