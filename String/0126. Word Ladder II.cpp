class Solution {
public:
	bool canTransform(const string& a, const string& b)
	{
		bool result = false;
		for (int i = 0; i < a.size(); ++i)
			if (a[i] != b[i])
			{
				if (result)
					return false;
				result = true;
			}
		return result;
	}
	void calc(vector<vector<string>>& result, vector<string>& wordList, vector<string>& prefix, int V, vector<int>& distance, vector<vector<int>>& prev)
	{
		prefix.push_back(wordList[V]);
		if (prev[V].empty())
		{
			result.push_back(prefix);
			reverse(result.back().begin(), result.back().end());
		}
		for (int U : prev[V])
			calc(result, wordList, prefix, U, distance, prev);
		prefix.pop_back();
	}
	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
		vector<vector<string>> result;
		if (find(wordList.begin(), wordList.end(), endWord) == wordList.end())
			return {};
		wordList.erase(remove(wordList.begin(), wordList.end(), beginWord), wordList.end());
		wordList.push_back(beginWord);
		int E = find(wordList.begin(), wordList.end(), endWord) - wordList.begin();
		int N = wordList.size();
		vector<vector<int>> prev(N);
		int const INF = N + 1;
		vector<int> distance(N, INF);
		queue<int> Q;
		Q.push(N - 1);
		distance[N - 1] = 0;
		while (!Q.empty())
		{
			int V = Q.front(); Q.pop();
			if (V == E)
				break;
			for (int U = 0; U < N; ++U)
				if (distance[V] + 1 <= distance[U] && canTransform(wordList[V], wordList[U]))
				{
					if (distance[V] + 1 < distance[U])
						Q.push(U);
					distance[U] = distance[V] + 1;
					prev[U].push_back(V);
				}
		}
		if (distance[E] < INF)
		{
			vector<string> prefix;
			calc(result, wordList, prefix, E, distance, prev);
		}
		return result;
	}
};