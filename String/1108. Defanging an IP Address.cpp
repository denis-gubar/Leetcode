class Solution {
public:
	string replace_all(const string& s, const string& what, const string& to)
	{
		string result;
		int start = 0;
		for (int finish = s.find(what); finish != string::npos; finish = s.find(what, start))
		{
			result.append(s, start, finish - start).append(to);
			start = finish + what.size();
		}
		result.append(s, start, s.size() - start);
		return result;
	}
	string defangIPaddr(string address) {
		return replace_all(address, ".", "[.]");
	}
};