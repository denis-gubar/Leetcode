class Solution {
public:
	long long countVowels(string word) {
		string vowels{ "aeiou" };
		int N = word.size();
		long long result = 0;
		long long A = 0;
		long long total = 0;
		for (int i = 0; i < N; ++i)
		{
			bool isVowel = (vowels.find(word[i]) != string::npos);
			A += isVowel;
			if (isVowel)
				total += i + 1;
			result += total;
		}
		return result;
	}
};