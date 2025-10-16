class Solution {
public:
	int minimumBuckets(string street) {
		int result = 0;
		int N = street.size();
		for (int i = 1; i < N - 1; ++i)
			if (street[i] == '.' && street[i - 1] == 'H' && street[i + 1] == 'H')
			{
				++result;
				street[i - 1] = street[i + 1] = 'X';
			}
		for (int i = 0; i < N; ++i)
			if (street[i] == 'H')
			{
				if (i > 0 && street[i - 1] == '.')
				{
					street[i] = 'X';
					++result;
				}
				else if (i + 1 < N && street[i + 1] == '.')
				{
					street[i] = 'X';
					++result;
				}
				else
					return -1;
			}
		return result;
	}
};