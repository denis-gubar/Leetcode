class Solution {
public:
	string removeKdigits(string num, int k) {
		string_view sv(num);
		string prefix;
		int start = 0, N = num.size();
		auto pos = sv.find('0');
		while (pos != string::npos && pos <= k)
		{
			if (sv.size() > pos)
				sv = sv.substr(pos + 1);
			else
				return "0";
			k -= pos;
			pos = sv.find('0');
		}
		for (char c = '1'; k && c <= '9'; ++c)
		{
			pos = sv.find(c);
			while (pos != string::npos && pos <= k)
			{
				if (sv.size() > pos)
					sv = sv.substr(pos + 1);
				else
					return "0";
				k -= pos;
				prefix += c;
				c = '0';
				pos = sv.find(c);
			}
		}
		string result = prefix;
		result += sv;
		while (k && !result.empty())
		{
			result.pop_back();
			--k;
		}
		if (result.empty())
			result = "0";
		return result;
	}
};
