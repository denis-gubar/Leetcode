class Solution {
public:
	int countSubstrings(string s, string t) {
		int result = 0;
		int N = s.size(), M = t.size();
		for(int startS = 0; startS < N; ++startS)
			for (int startT = 0; startT < M; ++startT)
			{
				int distinctCount = 0;
				for (int length = 1; startS + length <= N && startT + length <= M; ++length)
				{
					distinctCount += s[startS + length - 1] != t[startT + length - 1];
					if (distinctCount == 1)
						++result;
					if (distinctCount == 2)
						break;
				}
			}
		return result;
	}
};