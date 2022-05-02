class Solution {
public:
	bool checkString(string s) {
		int N = s.size();
		int A = N;
		int B = -1;
		for (int i = 0; i < N; ++i)
			if (s[i] == 'a')
				A = i;
		for (int i = N - 1; i >= 0; --i)
			if (s[i] == 'b')
				B = i;
        return A < B || A == N || B == -1;
	}
};
