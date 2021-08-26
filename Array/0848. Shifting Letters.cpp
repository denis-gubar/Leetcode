class Solution {
public:
	string shiftingLetters(string S, vector<int>& shifts) {
		int N = S.size();
		vector<int> A{ shifts };
		for (int i = N - 2; i >= 0; --i)
        {
			A[i] += A[i + 1];
            A[i] %= 26;
        }
		for (int i = 0; i < S.size(); ++i)
			S[i] = (S[i] - 'a' + A[i] % 26) % 26 + 'a';
		return S;
	}
};