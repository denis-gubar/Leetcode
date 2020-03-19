class Solution {
public:
	vector<int> arrayRankTransform(vector<int>& arr) {
		int rank = 0;
		map<int, int> M;
		vector<int> A(arr);
		sort(A.begin(), A.end());
		for (int a : A)
			if (M.find(a) == M.end())
				M[a] = ++rank;
		vector<int> result;
		for (int a : arr)
			result.push_back(M[a]);
		return result;
	}
};
