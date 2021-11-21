class Solution {
public:
	int maxConsecutiveAnswers(string answerKey, int k) {
		int result = 0;
		int N = answerKey.size();
		for (char c : string{ "FT" })
		{
			int a = 0, b = 0, z = 0;
			while (b < N)
			{
				if (answerKey[b] == c)
					++b;
				else
				{
					++b;
					++z;
					while (z > k)
					{
						z -= answerKey[a] != c;
						++a;
					}
				}
				result = max(result, b - a);
			}
		}
		return result;
	}
};