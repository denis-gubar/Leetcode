class Solution {
public:
	bool canReach(vector<int>& arr, int start) {
		bool result = false;
		int N = arr.size();
		vector<int> visited(N);
		queue<int> Q;
		Q.push(start);
		visited[start] = 1;
		while (!Q.empty())
		{
			int pos = Q.front(); Q.pop();
			int delta = arr[pos];
			for (int k = -1; k <= 1; k += 2)
			{
				int nPos = k * delta + pos;
				if (nPos >= 0 && nPos < N && !visited[nPos])
				{
					Q.push(nPos);
					visited[nPos] = 1;
				}
			}
		}
		for (int i = 0; i < N; ++i)
			result |= visited[i] && !arr[i];
		return result;
	}
};