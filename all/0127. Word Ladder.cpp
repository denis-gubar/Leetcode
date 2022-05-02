class Solution {
public:
	struct Trie
	{
		unordered_map<char, Trie*> children;
		int count = 0;
		void add(string const& s, int id)
		{
			Trie* root = this;
			++root->count;
			for (char c : s)
			{
				if (root->children.find(c) == root->children.end())
					root->children[c] = new Trie();
				root = root->children[c];
				++root->count;
			}
			root->count = id;
		}
	};
	void calc(Trie* a, Trie* b, vector<vector<int>>& connectivity)
	{
		if (a->children.empty())
		{
			connectivity[a->count].push_back(b->count);
			connectivity[b->count].push_back(a->count);
			return;
		}
		for (auto [c, next] : a->children)
			if (auto it = b->children.find(c); it != b->children.end())
				calc(next, it->second, connectivity);
	}
	void traverse(Trie* root, vector<vector<int>>& connectivity)
	{
		if (root->children.empty() || root->count == 1)
			return;
		for (auto it = root->children.begin(); it != root->children.end(); ++it)
		{
			for (auto nextIt = next(it); nextIt != root->children.end(); ++nextIt)
				calc(it->second, nextIt->second, connectivity);
			traverse(it->second, connectivity);
		}
	}
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		Trie* root = new Trie();
		int N = wordList.size();
		wordList.push_back(beginWord);
		for (int i = 0; i <= N; ++i)
			root->add(wordList[i], i);
		vector<vector<int>> connectivity(N + 1);
		traverse(root, connectivity);
		vector<int>	distances(N + 1);
		distances[N] = 1;
		queue<int> Q;
		Q.push(N);
		while (!Q.empty())
		{
			int V = Q.front(); Q.pop();
			if (wordList[V] == endWord)
				return distances[V];
			for (int U : connectivity[V])
				if (distances[U] == 0)
				{
					distances[U] = distances[V] + 1;
					Q.push(U);
				}
		}
		return 0;
	}
};