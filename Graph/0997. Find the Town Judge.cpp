class Solution {
public:
	int findJudge(int N, vector<vector<int>>& trust) {
		int result = -1;
		vector<int> visited(N + 1);
		for (vector<int> const& t : trust)
			visited[t[0]] = 1;
		for (int i = 1; i <= N; ++i)
			if (visited[i] == 0)
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