class Solution {
public:
	int superEggDrop(int K, int N) {
        if (K >= 15 || (1 << K) >= N)
        {
            int result = 0;
            while(N > 0)
                N >>= 1, ++result;
            return result;
        }
		int N_MAX = 10001;
		vector<vector<int>> M(N_MAX, vector<int>(15));
		for (int i = 1; i < 10001; ++i)
		{
			M[i][1] = i;
			for (int j = 2; j < 15; ++j)
				if (i < j)
					M[i][j] = M[i][i];
				else
					M[i][j] = min(10000, M[i - 1][j - 1] + M[i - 1][j] + 1);
		}
		int a = 1, b = N;
		while (a < b)
		{
			int middle = (a + b) / 2;
			int x = 10000;
			if (K < 15)
				x = M[middle][K];
			if (N <= x)
				b = middle;
			else
				a = middle + 1;
		}
		return a;
	}
};