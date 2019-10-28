class Solution {
public:
	int numTilePossibilities(string tiles) {
		int N = tiles.size();
		set<string> S;
		for (int x = 1; x < (1 << N); ++x)
		{
			string s;
			for (int k = 0; k < N; ++k)
				if (x & (1 << k))
					s += tiles[k];
			sort(s.begin(), s.end());
			if (S.find(s) == S.end())
			{
				do
				{
					S.insert(s);
				} while (next_permutation(s.begin(), s.end()));
			}
		}
		return S.size();
	}
};