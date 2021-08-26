struct MapSum
{
	MapSum(MapSum* parentTrie = nullptr) : children(vector<MapSum*>(26)), value(0), childSum(0), parent(parentTrie) {}

	~MapSum()
	{
		for (auto child : children)
			if (child)
				delete child;
	}

	void insert(const string& word, int val)
	{
		MapSum* node = this;
		for (int c : word)
		{
			if (!node->children[c - 'a'])
				node = node->children[c - 'a'] = new MapSum(node);
			else
				node = node->children[c - 'a'];			
		}
		int delta = val - node->value;
		node->value = val;
		if (delta)
			while (node != this)
			{
				node->childSum += delta;
				node = node->parent;
			}
	}

	int sum(const string& prefix)
	{
		MapSum* node = this;
		for (int c : prefix)
			if (!node->children[c - 'a'])
				return 0;
			else
				node = node->children[c - 'a'];
		return node->childSum;
	}

	vector<MapSum*> children;
	int value;
	int childSum;
	MapSum* parent;
};