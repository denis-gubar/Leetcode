class Solution {
public:
	int calc(string const& s, int x, int y)
	{
		int result = 0;
		string t(s);
		string z;
		int q = t.size() + 1;
		while (q > t.size())
		{
			q = t.size();
			string z;
			for (int i = 0; i < t.size(); ++i)
			{
				char c = t[i];
				if (!z.empty() && z.back() == 'a' && c == 'b')
				{
					result += x;
					z.pop_back();
				}
				else
					z.push_back(c);
			}
			t = z;
			z.clear();
			for (int i = 0; i < t.size(); ++i)
			{
				char c = t[i];
				if (!z.empty() && z.back() == 'b' && c == 'a')
				{
					result += y;
					z.pop_back();
				}
				else
					z.push_back(c);
			}
			t = z;
		}
		return result;
	}
	int maximumGain(string s, int x, int y) {
		int result = 0;
		s += '$';
		string buffer;
		for (char c : s)
		{
			if (c == 'a' || c == 'b')
				buffer += c;
			else if (!buffer.empty())
			{
				int current = calc(buffer, x, y);
				reverse(buffer.begin(), buffer.end());
				result += max(current, calc(buffer, y, x));
				buffer.clear();
			}
		}
		return result;
	}
};