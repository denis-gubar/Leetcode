class Solution {
public:
	vector<vector<string>> displayTable(vector<vector<string>>& orders) {
		vector<vector<string>> result;
		map<int, map<string, int>> Table;
		vector<string> items;
		for (vector<string> const& order : orders)
		{
			++Table[stoi(order[1])][order[2]];
			items.push_back(order[2]);
		}
		sort(items.begin(), items.end());
		items.resize(unique(items.begin(), items.end()) - items.begin());
		items.insert(items.begin(), "Table");
		result.emplace_back(items);
		for (auto const& t : Table)
		{
			vector<string> line;
			line.emplace_back(to_string(t.first));
			for (int i = 1; i < items.size(); ++i)
			{
				int x = 0;
				if (auto it = t.second.find(items[i]); it != t.second.end())
					x = it->second;
				line.emplace_back(to_string(x));
			}
			result.emplace_back(line);
		}
		return result;
	}
};