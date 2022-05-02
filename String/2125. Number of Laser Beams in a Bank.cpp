class Solution {
public:
	int numberOfBeams(vector<string>& bank) {
		int N = bank.size();
		int result = 0;
		vector<int> A;
		for (int i = 0; i < N; ++i)
		{
			int x = count(bank[i].begin(), bank[i].end(), '1');
			if (x > 0)
				A.push_back(x);
		}
		for (int i = 1; i < A.size(); ++i)
			result += A[i - 1] * A[i];
		return result;
	}
};

