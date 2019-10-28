class Solution {
public:
	int bagOfTokensScore(vector<int>& tokens, int P) {
		sort(tokens.begin(), tokens.end());
		int a = 0, b = tokens.size() - 1, power = P, score = 0;
		int result = 0;
		while(true)
		{
			while (a <= b && tokens[a] <= power)
			{
				power -= tokens[a];
				++a; ++score;
			}
			result = max(result, score);
			if (!score || a >= b)
				break;
			power += tokens[b];
			--b; --score;
		}			
		return result;
	}
};
