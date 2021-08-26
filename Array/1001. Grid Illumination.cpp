class Solution {
public:
	vector<int> gridIllumination(int N, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
		vector<int> result;
		set<vector<int>> L;
		for (const vector<int>& lamp : lamps)
			L.insert(lamp);
		map<int, int> X, Y, D1, D2;
		for (const vector<int>& lamp : L)
		{
			int x = lamp[0], y = lamp[1];
			++X[x];
			++Y[y];
			++D1[y - x];
			++D2[y + x];
		}
		for (const vector<int>& query : queries)
		{
			int x = query[0], y = query[1];
			int answer = X.find(x) != X.end() || Y.find(y) != Y.end() ||
				D1.find(y - x) != D1.end() || D2.find(y + x) != D2.end();
			for(int nx = x - 1; nx <= x + 1; ++nx)
				for (int ny = y - 1; ny <= y + 1; ++ny)
				{
					auto it = L.find({ nx, ny });
					if (it != L.end())
					{
						L.erase(it);
						if (--X[nx] == 0)
							X.erase(nx);
						if (--Y[ny] == 0)
							Y.erase(ny);
						if (--D1[ny - nx] == 0)
							D1.erase(ny - nx);
						if (--D2[ny + nx] == 0)
							D2.erase(ny + nx);
					}
				}
			result.push_back(answer);
		}
		return result;
	}
};
