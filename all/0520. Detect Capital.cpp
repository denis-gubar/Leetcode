class Solution {
public:
	bool detectCapitalUse(string word) {
		int N = word.size(), capitalCount = 0;
		for (char c : word)
			if (c >= 'A' && c <= 'Z')
				++capitalCount;
		if (!capitalCount || capitalCount == N)
			return true;
		if (capitalCount == 1 && word[0] >= 'A' && word[0] <= 'Z')
			return true;
		return false;
	}
};