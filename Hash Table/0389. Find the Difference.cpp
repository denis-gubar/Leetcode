class Solution {
public:
	char findTheDifference(string s, string t) {
		vector<int> A(128), B(128);
		for (int c : s)
			++A[c];
		for (int c : t)
			++B[c];
		for (int i = 0; i < 128; ++i)
			if (A[i] != B[i])
				return i;
        return 0;
	}
};