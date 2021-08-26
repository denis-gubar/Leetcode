class Solution {
public:
	int longestPalindrome(string s) {
        if (s.empty())
            return 0;
		vector<int> A(128);
		for (int c : s)
			++A[c];
		sort(A.begin(), A.end(), [](int a, int b)
		{
			if (a % 2 != b % 2)
				return a % 2 > b % 2;
			return a > b;
		});
		int result = A[0];
		for (int i = 1; i < 128; ++i)			
			result += A[i] / 2 * 2;
		return result;
	}
};