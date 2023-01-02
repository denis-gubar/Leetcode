class Solution {
public:
	struct Trie
	{
		Trie(Trie* parentTrie = nullptr) : children(vector<Trie*>(26)), parent(parentTrie), sum(0) {}

		~Trie()
		{
			for (auto child : children)
				if (child)
					delete child;
		}

		/** Inserts a word into the trie. */
		void insert(const string& word, int delta)
		{
			Trie* node = this;
			for (int c : word)
				if (!node->children[c - 'a'])
					node = node->children[c - 'a'] = new Trie(node);
				else
					node = node->children[c - 'a'];
			node->sum = delta;
		}

		int search(const string& word)
		{
			Trie* node = this;
			for (int c : word)
				if (!node->children[c - 'a'])
					return 0;
				else
					node = node->children[c - 'a'];
			return node->sum;
		}

		vector<Trie*> children;
		Trie* parent;
		int sum;
	};
	vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
		Trie root;
		for (string const& s : positive_feedback)
			root.insert(s, 3);
		for (string const& s : negative_feedback)
			root.insert(s, -1);
		int N = report.size();
		vector<int> score(N);
		vector<int> A(N);
		iota(A.begin(), A.end(), 0);
		for (int i = 0; i < N; ++i)
		{
			string buffer;
			report[i].push_back(' ');
			for (char c : report[i])
				if (c == ' ')
				{
					score[i] += root.search(buffer);
					buffer.clear();
				}
				else
					buffer += c;
		}
		sort(A.begin(), A.end(), [&score, &student_id](int a, int b)
			{
				if (score[a] == score[b])
					return student_id[a] < student_id[b];
				return score[a] > score[b];
			});
		vector<int> result(k);
		for (int i = 0; i < k; ++i)
			result[i] = student_id[A[i]];
		return result;
	}
};

