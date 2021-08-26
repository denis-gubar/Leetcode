class Solution {
public:
	struct Trie
	{
		Trie(int id = -1) : id(id)
		{
		}
		void add(string const& s, int x)
		{
			Trie* node = this;
			for (char c : s)
            {
                if (node->children.find(c) == node->children.end())
					node->children[c] = new Trie();
                node = node->children[c];
            }
			node->id = x;
		}
		Trie* next(char c)
		{
			if (children.find(c) == children.end())
				return nullptr;
			return children[c];
		}
		unordered_map<char, Trie*> children;
		int id;
	};
	void calc(int x, int y, vector<vector<char>> const& board, Trie* trie, vector<vector<bool>>& path, unordered_set<int>& ids)
	{
		if (x >= board.size() || x < 0 || y >= board[0].size() || y < 0 || path[x][y])
			return;
		Trie* nextTrie = trie->next(board[x][y]);
		if (nextTrie)
		{
			path[x][y] = true;
			if (nextTrie->id >= 0)
				ids.insert(nextTrie->id);
			vector<int>	dx{ -1, 0, 1, 0 };
			vector<int>	dy{ 0, -1, 0, 1 };
			for (int z = 0; z < 4; ++z)
			{
				int nx = x + dx[z];
				int ny = y + dy[z];
				calc(nx, ny, board, nextTrie, path, ids);
			}
			path[x][y] = false;
		}
	}
	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		vector<string> result;
		unordered_set<int> ids;
		int N = board.size(), M = board[0].size();
		vector<vector<bool>> path(N, vector<bool>(M));
		Trie* trie = new Trie();
		for (int i = 0; i < words.size(); ++i)
			trie->add(words[i], i);
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
				calc(i, j, board, trie, path, ids);
		for (int id : ids)
			result.push_back(words[id]);
		return result;
	}
};