class Solution {
public:
	bool canMakeArithmeticProgression(vector<int>& A) {
		unordered_set<int> S;
        sort(A.begin(), A.end());
		for (int i = 1; i < A.size(); ++i)
			S.insert(A[i] - A[i - 1]);
		return S.size() == 1;
	}
};