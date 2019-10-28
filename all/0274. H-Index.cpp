class Solution {
public:
	int hIndex( vector<int>& citations ) {
		if (citations.empty())
			return 0;
		int n = citations.size();
		vector<int> A( citations );
		sort( A.begin(), A.end() );
		int position = n - 1, k = 0, h = n;
		while (true)
		{
			int g = 0, e = 0;
			for (int p = position; p >= 0; --p)
			{
				if (A[p] < h)
					break;
				if (A[p] > h)
					++g;
				if (A[p] == h)
					++e;
			}
			if (k + g + e >= h && k + g <= h)
				return h;
			position -= g;
			k += g;
			--h;
		}
		return 0;
	}
};