class Solution {
public:
	int minFlips(string target) {
		int result = 0;
		int N = target.size();
		char x = '0';
		for (int i = 0; i < N; ++i)
		{
			if (target[i] != x)
				x = target[i], ++result;
		}
		return result;
	}
};