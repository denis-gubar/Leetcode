class Solution {
public:
	int subarraysDivByK(vector<int>& A, int K) {
		int result = 0;
		vector<int> M(K);
		++M[0];
		int s = 0;
		for (int i = 0; i < A.size(); ++i)
		{
			s = A[i] + s + 5000 * K;
			s %= K;
			++M[s];
		}
		for (int x : M)
			result += x * (x - 1);
		return result / 2;
	}
};