class Solution {
public:
	vector<string> split(const string& s, char delimeter = ' ')
	{
		vector<string> result;
		istringstream ss(s);
		for (string token; !ss.eof(); )
		{
			getline(ss, token, delimeter);
			result.push_back(token);
		}
		return result;
	}
	int countValidWords(string sentence) {
		int result = 0;
		vector<string> S(split(sentence));
		vector<char> const dots{ '!', '.', ',' };
		for (string const& s : S)
			if (!s.empty())
			{
				int dash_count = count(s.begin(), s.end(), '-');
				if (dash_count > 1)
					continue;
				if (dash_count == 1 && (s[0] == '-' || s.back() == '-'))
					continue;
				bool isOk = true;
				for (char dot : dots)
				{
					int dot_count = count(s.begin(), s.end(), dot);
					isOk &= dot_count < 2;
					if (dot_count == 1 && s.back() != dot)
						isOk = false;
                    if (dot_count == 1 && s.back() == dot && s.size() > 1 && s[s.size() - 2] == '-')
                        isOk = false;
				}
				if (!isOk)
					continue;
				for (char digit = '0'; isOk && digit <= '9'; ++digit)
					if (count(s.begin(), s.end(), digit) > 0)
						isOk = false;
				result += isOk;
			}
		return result;
	}
};