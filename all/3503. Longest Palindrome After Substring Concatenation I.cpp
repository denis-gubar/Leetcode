static short z[2'005];
class Solution {
public:
	vector<short> calc(string const& s)
	{
		string p = "^";
		for (char c : s)
			p += '#', p += c;
		p += "#$";
		short N = p.size();
		vector<short> LPS(N);
		LPS[2] = 1;
		short C = 2, R = 3;
		for (short i = 3; i < N; ++i)
		{
			short iMirror = 2 * C - i;
			short diff = R - i;
			if (diff > 0)
				LPS[i] = min(LPS[iMirror], diff);
			while (p[i - LPS[i] - 1] == p[i + LPS[i] + 1])
				++LPS[i];
			if (i + LPS[i] > R)
				R = i + LPS[i], C = i;
		}
		return LPS;
	}
	void z_function(string const& s)
	{
		int N = s.size();
		memset(z, 0, sizeof(z));
		for (short i = 1, L = 0, R = 1; i < N; ++i)
		{
			if (i < R)
				z[i] = min<short>(R - i, z[i - L]);
			while (i + z[i] < N && s[z[i]] == s[i + z[i]])
				++z[i];
			if (i + z[i] > R)
				L = i, R = i + z[i];
		}
	}
	int search(string_view sv, string_view tv)
	{
		int result = 0;
		int N = sv.size();
		for (auto it = tv.begin(), end = prev(tv.end()); it != end; ++it)		
		{
			int current = 0;
			auto nit = it;
			auto sit = sv.begin();
			while (nit != end && sit != sv.end() && *nit == *sit)
				++current, ++nit, ++sit;
			result = max(result, current);
		}
		return result;
	}
	int longestPalindrome(string s, string t) {
		string rs(s.rbegin(), s.rend());
		string_view sv(s), tv(t), rsv(rs);
		string rs2 = rs + '#';
		string t2 = t + '!';
		string_view rsv2(rs2), tv2(t2);
		short const N = s.size(), M = t.size();
		vector<short> A = calc(s), B = calc(t), C = calc(s + t);
   		short result = *max_element(C.begin(), C.end());
		//s.substr((i - LPS[i]) / 2, LPS[i])
		for (short i = 0; i < A.size(); ++i)
			if (A[i] > 0)
			{
				result = max(result, A[i]);
				int length = N - (N - (i - A[i]) / 2);
				if (result >= A[i] + 2 * length)
					continue;
				z_function(rs.substr(N - length) + '#' + t);
				for (int j = length + 1; j < M + length + 1; ++j)
					if (z[j] > 0)
						result = max<short>(result, A[i] + 2 * z[j]);
			}
		for (short i = 0; i < B.size(); ++i)
			if (B[i] > 0)
			{
				result = max(result, B[i]);
				int length = M - ((i - B[i]) / 2 + B[i]);
				if (result >= B[i] + 2 * length)
					continue;
				z_function(t.substr(M - length) + '#' + rs);
				for (int j = length + 1; j < N + length + 1; ++j)
					if (z[j] > 0)
						result = max<short>(result, B[i] + 2 * z[j]);
			}
		return result;
    }
};
