class Solution {
public:
	int calc(string const& s, int pos, vector<string>& words)
	{
		int result = 0;
		for (int length = 1; length + pos <= s.size(); ++length)
		{
			bool flag = false;
			for(string const& w : words)
				if (w.size() == length)
				{
					bool f = true;
					for(int i = 0, x = pos; i < length; ++i, ++x)
						if (s[x] != w[i])
						{
							f = false;
							break;
						}
					if (f)
					{
						flag = true;
						break;
					}
				}
			if (!flag)
			{
				words.push_back(s.substr(pos, length));
				result = max(result, 1 + calc(s, pos + length, words));
				words.pop_back();
			}
		}
		return result;
	}
	int maxUniqueSplit(string s) {		
		vector<string> words;
		return calc(s, 0, words);
	}
};