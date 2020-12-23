class Solution {
public:
	int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
		vector<bool> F(2001);
		for (int f : forbidden)
			F[f] = true;
		unordered_map<int, int> M0;
		unordered_map<int, int> M1;
		M0[0] = 0;
		M1[0] = 0;
		queue<int> Q;
		Q.push(0); Q.push(0);
		while (!Q.empty())
		{
			int V = Q.front(); Q.pop();
			int d = Q.front(); Q.pop();
            if (V > 5'000 || V > 2'000 && a >= b)
                continue;
			if (d == 0)
			{
				if (V + a >= 2001 || !F[V + a])
				{
					auto it = M0.find(V + a);
					if (it == M0.end())
					{
						M0[V + a] = M0[V] + 1;
						Q.push(V + a); Q.push(0);
					}
				}
				if (V - b >= 0 && (V - b >= 2001 || !F[V - b]))
				{
					auto it = M1.find(V - b);
					if (it == M1.end())
					{
						M1[V - b] = M0[V] + 1;
						Q.push(V - b); Q.push(1);
					}
				}
			}
			else
			{
				if (V + a >= 2001 || !F[V + a])
				{
					auto it = M0.find(V + a);
					if (it == M0.end())
					{
						M0[V + a] = M1[V] + 1;
						Q.push(V + a); Q.push(0);
					}
				}
			}
		}
		int result = -1;
		if (M0.find(x) != M0.end() && (result == -1 || M0[x] < result))
			result = M0[x];
		if (M1.find(x) != M1.end() && (result == -1 || M1[x] < result))
			result = M1[x];
		return result;
	}
};