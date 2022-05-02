class Solution {
public:
	vector<int> findAllPeople(int N, vector<vector<int>>& meetings, int firstPerson) {
		vector<int> result;
		vector<bool> hasSecret(N);
		hasSecret[0] = hasSecret[firstPerson] = true;
		int M = meetings.size();
		vector<int> I(M);
		iota(I.begin(), I.end(), 0);
		sort(I.begin(), I.end(), [&meetings](int a, int b)
			{
				return meetings[a][2] < meetings[b][2];
			});
		for (int i = 0; i < M; ++i)
		{
			unordered_set<int> start;
			unordered_map<int, unordered_set<int>> F;
			int j = i;
			while (j + 1 < M && meetings[I[j + 1]][2] == meetings[I[i]][2])
				++j;
			for (int k = i; k <= j; ++k)
			{
				int const& x = meetings[I[k]][0];
				int const& y = meetings[I[k]][1];
                if (hasSecret[x] && hasSecret[y])
                    continue;
				if (hasSecret[x] || hasSecret[y])
                {
                    if (!hasSecret[x] && F.find(x) != F.end())
					    start.insert(x);
                    if (!hasSecret[y] && F.find(y) != F.end())
                        start.insert(y);                        
                    hasSecret[x] = hasSecret[y] = true;
                    continue;
                }
                F[y].insert(x);
                F[x].insert(y);
			}
			queue<int> Q;
			for (int x : start)
				Q.push(x);
			while (!Q.empty())
			{
				int x = Q.front(); Q.pop();
				for(int y : F[x])
					if (!hasSecret[y] && start.insert(y).second)
					{
						Q.push(y);
						hasSecret[y] = true;
					}
			}
			i = j;
		}
		for (int i = 0; i < N; ++i)
			if (hasSecret[i])
				result.push_back(i);
		return result;
	}
};