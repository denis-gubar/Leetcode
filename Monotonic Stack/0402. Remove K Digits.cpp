class Solution {
public:
	string removeKdigits(string num, int k) {
		string result(num);
		string prefix;
		auto pos = result.find('0');
		while (pos != string::npos && pos <= k)
		{
			result = result.size() > pos + 1 ? result.substr(pos + 1) : "";
			k -= pos;
			pos = result.find('0');
		}
		for (char c = '1'; k && c <= '9'; ++c)
		{
			pos = result.find(c);
			while (pos != string::npos && pos <= k)
			{
				result = result.size() > pos + 1 ? result.substr(pos + 1) : "";
				k -= pos;
				prefix += c;
				c = '0';
				pos = result.find(c);
			}
		}
		result = prefix + result;
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