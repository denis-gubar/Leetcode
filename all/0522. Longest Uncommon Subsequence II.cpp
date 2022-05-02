class Solution {
public:
	bool isSubsequence(string const& a, string const& b)
	{
		int sizeA = a.size();
		int sizeB = b.size();
		int posA = 0, posB = 0;
		while (posA < sizeA && posB < sizeB)
		{
			if (a[posA] == b[posB])
				++posB;
			++posA;
		}
		return posB == sizeB;
	}
	int findLUSlength(vector<string>& strs) {
		int result = -1;
		int N = strs.size();
		for (int i = 0; i < N; ++i)
		{
			int count = 0;
			for (int j = 0; j < N; ++j)
				count += isSubsequence(strs[j], strs[i]);
			if (count == 1)
				result = max<int>(result, strs[i].size());
		}
		return result;
	}
};