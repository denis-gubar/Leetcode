class Solution {
public:
	string largestMerge(string word1, string word2) {
		string result;
		int a = 0, b = 0;
		int N = word1.size(), M = word2.size();
		while (a < N || b < M)
		{
			if (word1[a] > word2[b])
			{
				result += word1[a];
				++a;
				continue;
			}
			if (word1[a] < word2[b])
			{
				result += word2[b];
				++b;
				continue;
			}
			int i = 1;
			while (a + i < N && b + i < M && word1[a + i] == word2[b + i] && word1[a + i] > word1[a])
				++i;
			if (word1.substr(a) + word2.substr(b) > word2.substr(b) + word1.substr(a))
			{
				result += word1.substr(a, i);
				a += i;
			}
			else
			{
				result += word2.substr(b, i);
				b += i;
			}
		}
		result += word1.substr(a);
		result += word2.substr(b);
		return result;
	}
};