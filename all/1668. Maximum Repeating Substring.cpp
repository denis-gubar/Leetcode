class Solution {
public:
	int maxRepeating(string sequence, string word) {
		int result = 0;
		int N = sequence.size();
		int M = word.size();
		for (int start = 0; start + (result + 1) * M <= N; ++start)
		{
			int k = 0;
			while (start + (k + 1) * M <= N && sequence.substr(start + k * M, M) == word)
				++k;
			result = max(result, k);
		}
		return result;
	}
};