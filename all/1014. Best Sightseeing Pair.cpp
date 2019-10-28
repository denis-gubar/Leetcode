class Solution {
public:
	int maxScoreSightseeingPair(vector<int>& A) {
		int result = -10000;
		multiset<int> S;
		for (int i = 0; i < A.size(); ++i)
			S.insert(A[i] - i);
		for (int i = 0; i + 1 < A.size(); ++i)
		{
			S.erase(S.find(A[i] - i));
			result = max(result, A[i] + i + *S.rbegin());
		}
		return result;
	}
};