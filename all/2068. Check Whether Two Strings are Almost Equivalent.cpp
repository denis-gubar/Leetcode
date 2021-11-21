class Solution {
public:
	bool checkAlmostEquivalent(string word1, string word2) {
		vector<int> A(256), B(256);
		for (char c : word1)
			++A[c];
		for (char c : word2)
			++B[c];
		for (int i = 'a'; i <= 'z'; ++i)
			if (abs(A[i] - B[i]) > 3)
				return false;
		return true;
	}
};