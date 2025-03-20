static int K;
static size_t best;
class Solution {
public:
	struct Trie
	{
		Trie(): count(0), length(0)
		{
		}
		void add(string const& s, int id)
		{
			Trie* node = this;
			++node->count;
			for (char c : s)
			{
				if (node->children.find(c) == node->children.end())
				{
					size_t l = node->length + 1;
					node->children[c] = new Trie();
					node->children[c]->length = l;
				}
				node = node->children[c];
				++node->count;
			}
		}
		Trie* check(string const& s)
		{
			Trie* node = this;
			for (char c : s)
			{
				if (node->count > K)
					best = max(best, node->length);
				if (node->children[c]->count < K)
				{
					if (node->count == K)
						return node;
					return nullptr;
				}
				node = node->children[c];
			}
			if (node->count > K)
				best = max(best, node->length);
			if (node->count == K)
				return node;
			return nullptr;
		}
		unordered_map<char, Trie*> children;
		size_t count;
		size_t length;
	};
	vector<int> longestCommonPrefix(vector<string>& words, int k) {
		K = k;
		best = 0;
		int const N = words.size();
		vector<int> result(N);
		Trie root;
		for (int i = 0; i < N; ++i)
			root.add(words[i], i);
		unordered_map<Trie*, vector<int>> M;
		for (int i = 0; i < N; ++i)
			if (Trie* node = root.check(words[i]); node != nullptr)
				M[node].push_back(i);
		set<pair<size_t, Trie*>> S;
		S.insert({ best, nullptr });
		for (auto const& [key, value] : M)
			S.insert({ key->length, key });
		for (int i = 0; i < N; ++i)
		{
			Trie* node = root.check(words[i]);
			if (node == nullptr)
			{
				S.erase(S.find({ best, nullptr }));
				if (!S.empty())
					result[i] = max(best, prev(S.end())->first);
				else
					result[i] = best;
				S.insert({ best, nullptr });
			}
			else
			{
				S.erase(S.find({ node->length, node }));
				if (!S.empty())
					result[i] = max(best, prev(S.end())->first);
				else
					result[i] = best;
				S.insert({ node->length, node });
			}
		}
		return result;
    }
};
