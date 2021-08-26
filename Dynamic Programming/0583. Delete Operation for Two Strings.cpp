class Solution {
public:
	int minDistance(string word1, string word2) {
		if (word1.size() < word2.size())
			word1.swap(word2);
		int a = word1.size(), b = word2.size();
		vector<int> Prev(a + 1), Cur(a + 1);
		for (int i = 0; i <= a; ++i)
			Cur[i] = i;
		for (int i = 0; i < b; ++i)
		{
			Cur.swap(Prev);
			Cur[0] = i + 1;
			for (int j = 1; j <= a; ++j)
			{
				Cur[j] = min(Cur[j - 1] + 1, Prev[j] + 1);
				if (word1[j - 1] == word2[i])
					Cur[j] = min(Cur[j], Prev[j - 1]);
				else
					Cur[j] = min(Cur[j], Prev[j - 1] + 2);
			}
		}
		return Cur[a];
	}
};