class Solution {
public:
	int calc(vector<int> const& A)
	{
		int result = 0;
		for (int x : A)
			result += x > 0;
		return result;
	}
	int numSplits(string s) {
		int result = 0;
		int N = s.size();
		vector<int> M(26), A(26);		
		for (int i = 0; i < N; ++i)
			++M[s[i] - 'a'];
		int mDistinct = calc(M), aDistinct = 0;
		for (int i = 0; i < N; ++i)
		{
			if (--M[s[i] - 'a'] == 0)
				--mDistinct;
			if (++A[s[i] - 'a'] == 1)
				++aDistinct;
			result += mDistinct == aDistinct;
		}		
		return result;
	}
};