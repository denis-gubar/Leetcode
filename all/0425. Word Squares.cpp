class Solution {
public:
	struct Trie
	{
		unordered_map<char, Trie*> children;
		string prefix;
		void add(string const& word)
		{
			Trie* node = this;
			for (char c : word)
			{
				if (node->children.find(c) == node->children.end())
					node->children[c] = new Trie();
				node->children[c]->prefix = node->prefix + c;
				node = node->children[c];
			}
		}
	};
	void calc(vector<Trie*>& nodes, int row, int col, vector<vector<string>>& result)
	{
		if (row == N)
		{
			result.push_back({});
			for (Trie* node : nodes)
				result.back().push_back(node->prefix);
			return;
		}
		vector<char> next_characters;
		for (auto [c, dummy] : nodes[row]->children)
			next_characters.push_back(c);
		for (char c : next_characters)
		{
			vector<Trie*> next_nodes(nodes);
			next_nodes[row] = next_nodes[row]->children[c];
			if (col > row)
			{
				auto it = next_nodes[col]->children.find(c);
				if (it == next_nodes[col]->children.end())
					continue;
				next_nodes[col] = it->second;
			}
			if (col + 1 < N)
				calc(next_nodes, row, col + 1, result);
			else
				calc(next_nodes, row + 1, row + 1, result);
		}
	}
	int N;
	vector<vector<string>> wordSquares(vector<string>& words) {
		Trie* root = new Trie();
		for (string const& word : words)
			root->add(word);
		N = words[0].size();
		vector<vector<string>> result;
		vector<Trie*> nodes(N, root);
		calc(nodes, 0, 0, result);
		return result;
	}
};