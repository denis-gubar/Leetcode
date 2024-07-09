class Solution {
public:
	string target;
	int N, T;
	vector<int> calc(string s)
	{
		int X = s.size();
		s.reserve(X + T + 1);
		s += '#';
		s += target;
		int N = s.size();
		vector<int> z(N);
		for (int i = 1, L = 0, R = 1; i < N; ++i)
		{
			if (i < R)
				z[i] = min(R - i, z[i - L]);
			while (i + z[i] < N && s[z[i]] == s[i + z[i]])
				++z[i];
			if (i + z[i] > R)
				L = i, R = i + z[i];
		}
		vector<int> result;
		int size = 0;
		for (int i = X + 1; i < N; ++i)
			size += z[i] == X;
		result.reserve(size);
		for (int i = X + 1; i < N; ++i)
			if (z[i] == X)
				result.push_back(i - X - 1);
		return result;
	}
	int minimumCost(string target, vector<string>& words, vector<int>& costs) {
        int const INF = 1 << 30;
		T = target.size();
        N = words.size();
		unordered_map<string, pair<int, int>> M;
		for (int i = 0; i < N; ++i)
			if (auto it = M.find(words[i]); it != M.end())
			{
				if (it->second > pair<int, int>{costs[i], i})
					it->second = { costs[i], i };
			}
			else
				M[words[i]] = { costs[i], i };
		vector<string> W;
		vector<int> C;
		W.reserve(N);
		C.reserve(N);
		for (int i = 0; i < N; ++i)
			if (M[words[i]].second == i)
				C.push_back(costs[i]), W.push_back(words[i]);
		swap(W, words);
		swap(C, costs);
		N = words.size();
		this->target = target;
		vector<vector<int>> Z;
		Z.reserve(N);
		for (int i = 0; i < N; ++i)
			Z.emplace_back(calc(words[i]));
		vector<vector<int>> connectivity(T + 1);
		for(int i = 0; i < N; ++i)
			for (int j : Z[i])
				connectivity[j].push_back(i);
		vector<int> minDistance(T + 1, INF);
		minDistance[0] = 0;
		set<pair<int, int>> activeVertices;
		activeVertices.insert({ 0, 0 });
		while (!activeVertices.empty())
		{
			int node = activeVertices.begin()->second;
			activeVertices.erase(activeVertices.begin());
			for (auto next : connectivity[node])
			{
				int const first = node + words[next].size();
				int const second = costs[next];
				if (minDistance[first] > minDistance[node] + second)
				{
					activeVertices.erase({ minDistance[first], first });
					minDistance[first] = minDistance[node] + second;
					activeVertices.insert({ minDistance[first], first });
				}
			}
		}
		if (minDistance[T] == INF)
			return -1;
        return minDistance[T];
    }
};
