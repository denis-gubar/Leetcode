class Solution {
public:
	int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
		int result = 0;
		int index = 0;
		if (ruleKey == "color")
			index = 1;
		if (ruleKey == "name")
			index = 2;
		for (vector<string> const& item : items)
			if (item[index] == ruleValue)
				++result;
		return result;
	}
};