class Solution {
public:
	struct BinaryTrie
	{
		BinaryTrie() : left(nullptr), right(nullptr), count(0) {}
		~BinaryTrie()
		{
			if (left)
				delete left;
			if (right)
				delete right;
		}
		void add(int x)
		{
			bitset<18> B(x);
			BinaryTrie* node = this;
			for (int i = 17; i >= 0; --i)
			{
				if (!node->right)
					node->right = new BinaryTrie;
				if (!node->left)
					node->left = new BinaryTrie;
				if (B[i])
					node = node->right;
				else
					node = node->left;
				++node->count;
			}
		}
		void remove(int x)
		{
			bitset<18> B(x);
			BinaryTrie* node = this;
			for (int i = 17; i >= 0; --i)
			{
				if (B[i])
					node = node->right;
				else
					node = node->left;
				--node->count;
			}
		}
		int max(int value)
		{
			bitset<18> B(value);
			BinaryTrie* node = this;
			int result = 0;
			for (int i = 17; i >= 0; --i)
			{
				bool nextBit = false;
				if (B[i])
					nextBit = node->left->count == 0;
				else
					nextBit = node->right->count > 0;
				if (nextBit)
					node = node->right;
				else
					node = node->left;
				result |= (B[i] ^ nextBit) << i;
			}
			return result;
		}
		BinaryTrie* left;
		BinaryTrie* right;
		int count;
	};
	void calc(int root)
	{
		bt.add(root);
		for (auto const& [val, i] : A[root])
			result[i] = bt.max(val);
		for (int child : children[root])
			calc(child);
		bt.remove(root);
	}
	vector<int> maxGeneticDifference(vector<int>& parents, vector<vector<int>>& queries) {
		int N = parents.size();
		int Q = queries.size();
		result = vector<int>(Q);
		A = vector<vector<pair<int, int>>>(N);
		children = vector<vector<int>>(N);
		for (int i = 0; i < Q; ++i)
		{
			int const& node = queries[i][0];
			int const& val = queries[i][1];
			A[node].emplace_back(val, i);
		}
		int root = -1;
		for (int i = 0; i < N; ++i)
			if (parents[i] == -1)
				root = i;
			else
				children[parents[i]].push_back(i);
        calc(root);
		return result;
	}
	BinaryTrie bt;
	vector<int> result;
	vector<vector<int>> children;
	vector<vector<pair<int, int>>> A;
};