class Solution {
public:
	string reverseOnlyLetters(string S) {
		string result;
		string letters;
		for (char c : S)
			if (isalpha(c))
				letters.push_back(c);
		for (char c : S)
			if (isalpha(c))
			{
				result += letters.back();
				letters.pop_back();
			}
			else
				result += c;
		return result;
	}
};