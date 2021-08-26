class ThroneInheritance {
public:
	ThroneInheritance(string kingName): king(kingName) {
	}

	void birth(string parentName, string childName) {
		children[parentName].push_back(childName);
	}

	void death(string name) {
		dead.insert(name);
	}

	void calc(vector<string>& curOrder, string const& node)
	{
		if (node.empty())
			return;
		curOrder.push_back(node);
		for (string const& next : children[node])
			calc(curOrder, next);
	}

	vector<string> getInheritanceOrder() {
		vector<string> curOrder;
		calc(curOrder, king);
		vector<string> result;
		for (string const& s : curOrder)
			if (dead.find(s) == dead.end())
				result.push_back(s);
		return result;
	}
	string king;
	unordered_set<string> dead;	
	unordered_map<string, vector<string>> children;
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */