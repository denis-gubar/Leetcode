class Solution {
public:
	int tilingRectangle(int n, int m) {
		int result = 0;
		map<vector<int>, int> M;
		vector<vector<int>> Q;
		vector<int> finish(m, n);
		Q.push_back(vector<int>(m));
		while (true)
		{
			vector<vector<int>> NQ;
			for (vector<int> const& q : Q)
			{
				if (q == finish)
					return result;
				int i = 0;
				while (q[i] == n)
					++i;
				for (int k = 1; q[i] + k <= n && i + k <= m; ++k)
                {
                    vector<int> nq(q);
                    for (int a = 0; a < k; ++a)
                        nq[i + a] += k;
                    NQ.push_back(nq);
                }
			}
			Q = move(NQ);
			++result;
		}
		return -1;
	}
};