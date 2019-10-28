class Solution {
public:
	string toBinary(int n)
	{
		string r;
		while (n != 0)
		{
			r = (n % 2 == 0 ? "0" : "1") + r;
			n /= 2;
		}
		return r;
	}
	bool queryString(string S, int N) {
		if (N > 100000)
			return false;
		for (int x = 1; x <= N; ++x)
		{
			if (S.find(toBinary(x)) == string::npos)
				return false;
		}
		return true;
	}
};