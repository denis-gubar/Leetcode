class Solution {
public:
	string decodeAtIndex(string S, int K) {
		long long k = 0;
		int pos = 0;
		long long d = 1;
		while (pos < S.size() && k < K)
		{
			if (isdigit(S[pos]))
			{
				d = S[pos] - '0';
				k *= d;
			}
			else
			{
				++k;
			}
			++pos;
		}
		if (k == K)
		{
			--pos;
			while (isdigit(S[pos]))
				--pos;
			return S.substr(pos, 1);
		}
		k /= d;
		K = (K - 1) % k + 1;
		return decodeAtIndex(S.substr(0, pos), K);
	}
};