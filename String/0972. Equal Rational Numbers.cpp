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

	string calc(string s)
	{
		s = replace_all(s, "(9999)", "(9)");
		s = replace_all(s, "(999)", "(9)");
		s = replace_all(s, "(99)", "(9)");
		s = replace_all(s, "(0000)", "");
		s = replace_all(s, "(000)", "");
		s = replace_all(s, "(00)", "");
		s = replace_all(s, "(0)", "");
		int x = 0;
		string y, period;
		int state = 0;
		for (char c : s)
		{
			if (state == 0 && c != '.')
				x = x * 10 + (c - '0');
			else if (state == 0 && c == '.')
				state = 1;
			else if (state == 1 && c != '(')
				y += c;
			else if (state == 1 && c == '(')
				state = 2;
			else if (state == 2 && c != ')')
				period += c;
		}
		int N = x;
		int z = 1;
		int k = y.size();
		if (y != "")
		{
			for (int i = 0; i < k; ++i)
				z *= 10;
			N *= z;
			N += atoi(y.c_str());
		}
		if (period == "9")
			++N, period = "";
		string result = to_string(N / z) + '.' + to_string(z + N % z).substr(1);
		if (period == "")
		{
			while (result.back() == '0')
				result.pop_back();
		}
		for (int i = 0; i < 105 && result.size() < 105; ++i)
			result += period;
		result = result.substr(0, 100);
		return result;
	}
	bool isRationalEqual(string S, string T) {
		return calc(S) == calc(T);
	}
};