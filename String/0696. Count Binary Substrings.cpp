class Solution {
public:
	int countBinarySubstrings(string s) {
		int result = 0;
		vector<int> A{ 1 };
		for (int i = 1; i < s.size(); ++i)
		{
			if (s[i] == s[i - 1])
				++A.back();
			else
				A.push_back(1);
		}
		for (int i = 1; i < A.size(); ++i)
			result += min(A[i - 1], A[i]);
		return result;
	}
};