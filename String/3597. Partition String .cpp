class Solution {
public:
	struct Trie
	{
		Trie()
		{
		}
		unordered_map<char, Trie*> children;
	};
    vector<string> partitionString(string s) {
		Trie T;
		int const N = s.size();
		vector<string> result;
		result.reserve(N);
		Trie* node = &T;
		string buffer;
		buffer.reserve(N);
		for (char c : s)
		{
			buffer += c;
			if (node->children.find(c) == node->children.end())
			{
				node->children[c] = new Trie();
				result.push_back(buffer);
				buffer.clear();
				node = &T;
				continue;
			}
			node = node->children[c];
		}
		return result;
    }
};
