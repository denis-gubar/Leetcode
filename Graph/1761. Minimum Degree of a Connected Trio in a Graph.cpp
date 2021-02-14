class Solution {
public:
	int minTrioDegree(int n, vector<vector<int>>& edges) {
		vector<vector<bool>> M(n, vector<bool>(n));
		vector<int> A(n);
		vector<bool> F(3 * n);
		for (int i = 0; i < edges.size(); ++i)
		{
			int V = edges[i][0] - 1;
			int U = edges[i][1] - 1;
			M[V][U] = M[U][V] = true;
			++A[V];
			++A[U];
		}
		for (int V = 0; V < n; ++V)
			if (A[V] > 1)
				for (int U = V + 1; U < n; ++U)
					if (A[U] > 1 && M[V][U])
						for (int R = U + 1; R < n; ++R)
							if (A[R] > 1 && M[U][R] && M[V][R])
								F[A[V] + A[U] + A[R] - 6] = true;
		for (int k = 0; k < 3 * n; ++k)
			if (F[k])
				return k;
		return -1;
	}
};