class Solution {
public:
	bool validWordAbbreviation(string word, string abbr) {
		int pos = 0, i = 0;
		for (; pos < word.size() && i < abbr.size(); ++i)
		{
			if (isdigit(abbr[i]))
			{
				int digits = 0;
				int k = i;
				for (; k < abbr.size() && isdigit(abbr[k]); ++k)
                {
					digits = digits * 10 + abbr[k] - '0';
                    if (digits == 0)
                        return false;
                }
				i = k - 1;
				pos += digits;
			}
			else if (word[pos] != abbr[i])
				return false;
            else
                ++pos;
		}
		return pos == word.size() && i == abbr.size();
	}
};