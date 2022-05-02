class Solution {
public:
	vector<int> goodDaysToRobBank(vector<int>& security, int time) {
		vector<int> result;
		int N = security.size();
		vector<int> A(N), B(N);
        B.back() = N - 1;
		for (int i = 1; i < N; ++i)
			if (security[i - 1] >= security[i])
				A[i] = A[i - 1];
			else
				A[i] = i;
		for (int i = N - 2; i >= 0; --i)
			if (security[i + 1] >= security[i])
				B[i] = B[i + 1];
			else
				B[i] = i;
		for (int i = time; i + time < N; ++i)
			if (i - A[i] >= time && B[i] - i >= time)
				result.push_back(i);
		return result;
	}
};