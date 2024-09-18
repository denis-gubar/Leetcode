class Solution {
public:
	string removeVowels(string S) {
		string const vowels("aeiou");
        S.resize(stable_partition(S.begin(), S.end(), [&vowels](char c)
        {
            return vowels.find(c) == string::npos;
        }) - S.begin());
		return S;
	}
};