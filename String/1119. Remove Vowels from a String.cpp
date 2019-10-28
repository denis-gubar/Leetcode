class Solution {
public:
	string removeVowels(string S) {
		string vowels("aeiou");
		string result;
		for (char c : S)
			if (vowels.find(c) == string::npos)
				result += c;
		return result;
	}
};