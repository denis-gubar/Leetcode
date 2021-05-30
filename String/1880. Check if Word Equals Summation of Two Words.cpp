class Solution {
public:
	int calc(string const& s)
	{
		int result = 0;
		for (int c : s)
			result = result * 10 + (c - 'a');
		return result;
	}
	bool isSumEqual(string firstWord, string secondWord, string targetWord) {
		return calc(firstWord) + calc(secondWord) == calc(targetWord);
	}
};