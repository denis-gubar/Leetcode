class Solution {
public:
	int nextBeautifulNumber(int n) {
		set<int> S;
		for (int mask = 1; mask < (1 << 6); ++mask)
		{
			string s;
			for(int k = 0; k < 6; ++k)
				if (mask & (1 << k))
				{
					for (int z = 0; z <= k; ++z)
						s += '1' + k;
				}
			if (s.size() > 7 || s.size() == 7 && s[0] != '1')
				continue;
			do 
			{
				S.insert(stoi(s));
			} while (next_permutation(s.begin(), s.end()));
		}
		return *S.upper_bound(n);
	}
};