class Solution {
public:
	string reformatNumber(string number) {
		string result;
		string s;
		for (char c : number)
			if (isdigit(c))
				s += c;
		reverse(s.begin(), s.end());
		while (s.size() > 4)
		{
			result += s.back(); s.pop_back();
			result += s.back(); s.pop_back();
			result += s.back(); s.pop_back();
			result += '-';
		}
		if (s.size() == 4)
		{
			result += s.back(); s.pop_back();
			result += s.back(); s.pop_back();
			result += '-';
			result += s.back(); s.pop_back();
			result += s.back(); s.pop_back();
		}
		else
		{
			reverse(s.begin(), s.end());
			result += s;
		}
		return result;
	}
};