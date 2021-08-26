class Solution {
public:
	string s, p;
	int n, m;
	bool calc(int startS, int endS, int startP, int endP)
	{
		if (startP == endP)
			return startS == endS;
		if (p[startP + 1] == '*')
		{
			if (calc(startS, endS, startP + 2, endP))
				return true;
			for (int i = startS; i < n && (s[i] == p[startP] || p[startP] == '.'); ++i)
				if (calc(i + 1, endS, startP + 2, endP))
					return true;
			return false;
		}
		if (s[startS] != p[startP] && p[startP] != '.')
			return false;
		return calc(startS + 1, endS, startP + 1, endP);
	}
	bool isMatch(string s, string p) {
		n = s.size(), m = p.size();
		this->s = s, this->p = p;
		this->s += ' ', this->p += ' ';
		return calc(0, n, 0, m);
	}
};