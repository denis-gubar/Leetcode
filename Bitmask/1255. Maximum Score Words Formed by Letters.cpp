class Solution {
public:
	int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
		int N = words.size();
		vector<int> wordScore(N);
		vector<vector<int>> wordCount(N, vector<int>(26));
		vector<int> letterCount(26);
		for (int c : letters)
			++letterCount[c - 'a'];
		for (int i = 0; i < N; ++i)
			for (int c : words[i])
			{
				wordScore[i] += score[c - 'a'];
				++wordCount[i][c - 'a'];
			}
		int result = 0;
		for (int x = 1; x < (1 << N); ++x)
		{
			vector<int> currentCount(26);
			int currentScore = 0;
			for(int k = 0; k < N; ++k)
				if (x & (1 << k))
				{
					for (int i = 0; i < 26; ++i)
						currentCount[i] += wordCount[k][i];
					currentScore += wordScore[k];
				}
			bool isGood = true;
			if (result < currentScore)
			{
				for (int i = 0; i < 26; ++i)
					isGood &= currentCount[i] <= letterCount[i];
				if (isGood)
					result = currentScore;
			}
		}
		return result;
	}
};