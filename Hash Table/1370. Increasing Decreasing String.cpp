class Solution {
public:
	string sortString(string s) {
		string result;
		vector<int> count(26);
		for (char c : s)
			++count[c - 'a'];
		while (result.size() < s.size())
		{
			int lastI = 26;
			for(int i = 0; i < 26; ++i)
				if (count[i])
				{
					--count[i];
					result += 'a' + i;
					lastI = i;
					break;
				}
			int nextI = 0;
			while (nextI < 26)
			{
				nextI = 26;
				for (int i = lastI + 1; i < 26; ++i)
					if (count[i])
					{
						--count[i];
						result += 'a' + i;
						lastI = i;
						nextI = i;
						break;
					}
			}
            if (result.size() == s.size()) break;
			lastI = 26;
			for (int i = 25; i >= 0; --i)
				if (count[i])
				{
					--count[i];
					result += 'a' + i;
					lastI = i;
					break;
				}
			nextI = 0;
			while (nextI < 26)
			{
				nextI = 26;
				for (int i = lastI - 1; i >= 0; --i)
					if (count[i])
					{
						--count[i];
						result += 'a' + i;
						lastI = i;
						nextI = i;
						break;
					}
			}
		}
		return result;
	}
};