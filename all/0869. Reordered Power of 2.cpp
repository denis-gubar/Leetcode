class Solution {
public:
	bool reorderedPowerOf2(int N) {
		string S = to_string(N);
		sort(S.begin(), S.end());
		vector<string> A(31);
		for (int i = 0; i < 31; ++i)
		{
			string T = to_string(1 << i);
			sort(T.begin(), T.end());
			A[i] = T;
		}
		return find(A.begin(), A.end(), S) != A.end();
	}
};