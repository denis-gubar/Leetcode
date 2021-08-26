class Solution {
public:
	string mergeAlternately(string word1, string word2) {
		string result;
		int A = word1.size(), B = word2.size();
		for (int i = 0; i < max(A, B); ++i)
		{
			if (i < A)
				result += word1[i];
			if (i < B)
				result += word2[i];
		}
		return result;
	}
};