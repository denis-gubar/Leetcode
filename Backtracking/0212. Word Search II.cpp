int SIZE;
int DATA[100000][27];

class Solution {
	struct Trie
	{
		Trie()
		{
			clear();
		}
		void clear()
		{
			SIZE = 1;
			memset(DATA, 0, sizeof(DATA));
		}
		bool add(const string& s)
		{
			if (SIZE + s.size() >= 1000000)
				return false;
			int node = 0;
			for (int i = 0; i < s.size(); ++i)
			{
				if (!DATA[node][s[i] - 'a'])
				{
					DATA[node][s[i] - 'a'] = SIZE;
					++SIZE;
				}
				node = DATA[node][s[i] - 'a'];
			}
			DATA[node][26] = 1;
			return true;
		}
		void remove(const string& s)
		{
			int node = 0, startPos = s.size() - 1, startNode = 0;
			for (int i = 0; i < s.size(); ++i)
			{
				bool hasOtherSublings = false;
				for (int j = 0; j < 27 && !hasOtherSublings; ++j)
					if (j != s[i] - 'a' && DATA[node][j])
						hasOtherSublings = true;
				if (hasOtherSublings)
					startPos = s.size() - 1, startNode = node;
				else if (startPos == s.size() - 1)
					startPos = i, startNode = node;
				node = DATA[node][s[i] - 'a'];
			}			
			for (int i = startPos, node = startNode; i < s.size(); ++i)
			{
				int nextNode = DATA[node][s[i] - 'a'];
				DATA[node][s[i] - 'a'] = 0;
				node = nextNode;
			}
		}
		int search(int node, int c)
		{
			return DATA[node][c - 'a'];
		}
	};
	static const char END_OF_WORD = 'a' + 26;
public:
	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		vector<string> result;
		vector<int> dx{ 0, 1, 0, -1 };
		vector<int> dy{ 1, 0, -1, 0 };
		Trie trie;
		int pos = 0, n = board.size(), m = board[0].size();
		while (pos < words.size())
		{
			while (pos < words.size() && trie.add(words[pos]))
				++pos;
			for(int i = 0; i < n; ++i)
				for (int j = 0; j < m; ++j)
				{
					int node = trie.search(0, board[i][j]);
					if (!node)
						continue;
					string s(1, board[i][j]), path;
					queue<string> q;
					q.push(s); q.push(path);
					queue<int> I;
					I.push(node);
					while (!q.empty())
					{
						s = move(q.front()); q.pop();
						path = move(q.front()); q.pop();
						node = I.front(); I.pop();
						if (trie.search(node, END_OF_WORD))
						{
							result.push_back(s);
							trie.remove(s + END_OF_WORD);
						}
						int x = i, y = j;
						set<pair<int, int>> visited;
						visited.insert({ x, y });
						for (int p : path)
						{
							x += dx[p], y += dy[p];
							visited.insert({ x, y });
						}
						for (char i = 0; i < 4; ++i)
						{
							int nx = x + dx[i], ny = y + dy[i];
							if (nx >= 0 && nx < n && ny >= 0 && ny < m && visited.find({ nx, ny }) == visited.end())
							{
								int nextNode = trie.search(node, board[nx][ny]);
								if (nextNode)
								{
									q.push(s + board[nx][ny]); q.push(path + i);
									I.push(nextNode);
								}
							}
						}
					}
				}
			trie.clear();
			if ( pos < words.size() )
				--pos;
		}
		return result;
	}
};