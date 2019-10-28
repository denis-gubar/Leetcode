class Solution {
public:
	vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
		vector<int> A(arr);
		sort(A.begin(), A.end());
		vector<int> B;
		for (int i = 1; i < A.size(); ++i)
			B.push_back(A[i] - A[i - 1]);
		int M = *min_element(B.begin(), B.end());
		vector<vector<int>> result;
		for (int i = 0; i < B.size(); ++i)
			if (B[i] == M)
				result.push_back({ A[i], A[i + 1] });
		return result;
	}
};