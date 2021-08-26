class Solution {
public:
	string removeDuplicateLetters(string s) {
		if (s.empty()) return {};
		string result;
		int N = s.size();
		vector<int>	A(N);
		vector<vector<int>> positions(26);
		for (int i = N - 1; i >= 0; --i)
		{
			A[i] = 1 << (s[i] - 'a');
			if (i < N - 1)
				A[i] |= A[i + 1];
		}
		int mask = A[0], pos = 0;
		for (int i = 0; i < N; ++i)
			positions[s[i] - 'a'].push_back(i);
		while (mask)
		{
			for(int i = 0; i < 26; ++i)
				if (mask & (1 << i))
				{
					auto it = lower_bound(positions[i].begin(), positions[i].end(), pos);
					if (it != positions[i].end())
					{
						int next_pos = *it;
						if ((A[next_pos] & mask) == mask)
						{
							mask ^= 1 << i;
							result += i + 'a';
                            pos = next_pos;
							break;
						}
					}
				}
		}
		return result;
	}
};