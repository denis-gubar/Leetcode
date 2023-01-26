class Solution {
public:
	int findJudge(int N, vector<vector<int>>& trust) {
		int result = -1;
		vector<bool> visited(N + 1);
		for (vector<int> const& t : trust)
			visited[t[0]] = true;
		for (int i = 1; i <= N; ++i)
			if (!visited[i])
            {
                int count = 1;
                for (vector<int> const& t : trust)
			        count += t[1] == i;
                if (count == N)
				    result = i;
            }
		return result;
	}
};