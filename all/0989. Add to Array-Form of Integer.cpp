class Solution {
public:
	vector<int> addToArrayForm(vector<int>& A, int K) {
		vector<int> result;
		reverse(A.begin(), A.end());
		int extra = K;
		for (int i = 0; extra || i < A.size(); ++i)
		{
			if (i < A.size())
				extra += A[i];
			result.push_back(extra % 10);
			extra /= 10;
		}
		reverse(result.begin(), result.end());
		return result;
	}
};