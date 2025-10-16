class Solution {
public:
	int numTilePossibilities(string tiles) {
        int result = 0;
		int N = tiles.size();
        sort(tiles.begin(), tiles.end());
		set<string> S;
		for (int x = 1; x < (1 << N); ++x)
		{
			string s;
			for (int k = 0; k < N; ++k)
				if (x & (1 << k))
					s += tiles[k];
			if (S.insert(s).second)
			{
				do
				{
					++result;
				} while (next_permutation(s.begin(), s.end()));
			}
		}
		return result;
	}
};