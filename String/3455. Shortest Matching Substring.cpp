class Solution {
public:
	vector<int> z_function(string const& s)
	{
		int N = s.size();
		vector<int> z(N);
		for (int i = 1, L = 0, R = 1; i < N; ++i)
		{
			if (i < R)
				z[i] = min(R - i, z[i - L]);
			while (i + z[i] < N && s[z[i]] == s[i + z[i]])
				++z[i];
			if (i + z[i] > R)
				L = i, R = i + z[i];
		}
		return z;
	}
    int shortestMatchingSubstring(string s, string p) {
		int const P = p.size(), N = s.size();
		int result = N + 1;
		string a, b, c;
		a.reserve(P);
		b.reserve(P);
		c.reserve(P);
		int bPos = p.find('*');
		a = p.substr(0, bPos);
		int cPos = p.rfind('*');
		b = p.substr(bPos + 1, cPos - bPos - 1);
		c = p.substr(cPos + 1);		
		vector<int> ZA = z_function(a + '#' + s);
		vector<int> ZB = z_function(b + '#' + s);
		vector<int> ZC = z_function(c + '#' + s);
		vector<int> A, B, C;
		A.reserve(P);
		B.reserve(P);
		C.reserve(P);
		if (a.size() == 0)
		{
			A.resize(N + 1);
			iota(A.begin(), A.end(), 0);
		}
		else
			for (int i = a.size() + 1, e = ZA.size(); i < e; ++i)
				if (ZA[i] == a.size())
					A.push_back(i - a.size() - 1);
		if (b.size() == 0)
		{
			B.resize(N + 1);
			iota(B.begin(), B.end(), 0);
		}
		else
			for (int i = b.size() + 1, e = ZB.size(); i < e; ++i)
				if (ZB[i] == b.size())
					B.push_back(i - b.size() - 1);
		if (c.size() == 0)
		{
			C.resize(N + 1);
			iota(C.begin(), C.end(), 0);
		}
		else
			for (int i = c.size() + 1, e = ZC.size(); i < e; ++i)
				if (ZC[i] == c.size())
					C.push_back(i - c.size() - 1);
		for (int m : B)
			if (m >= a.size())
			{
				auto itA = upper_bound(A.begin(), A.end(), m - a.size());
				if (itA == A.begin() && *itA > m - a.size())
					continue;
				--itA;
				int L = *itA;
				auto itC = lower_bound(C.begin(), C.end(), m + b.size());
				if (itC == C.end())
					break;
				int R = *itC + c.size();
				result = min(result, R - L);
			}
		if (result > N)
			result = -1;
		return result;
    }
};
