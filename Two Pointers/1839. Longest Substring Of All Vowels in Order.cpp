class Solution {
public:
	int longestBeautifulSubstring(string word) {
		string vowels{ "aeiou$" };
		int result = 0;
		int pos = 0;
		string buffer;
		for (char c : word)
		{
			int x = vowels.find(c);
			if ((x == pos || x == pos + 1) && (buffer.empty() && x == 0 || !buffer.empty()))
			{
				buffer += c;
				pos = x;
				if (pos == 4)
					result = max<int>(result, buffer.size());
			}
			else
			{
				buffer.clear();
				pos = 0;
				if (x == 0)
				{
					
					buffer += c;
				}
			}
		}
		return result;
	}
};