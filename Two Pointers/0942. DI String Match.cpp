class Solution {
public:
	vector<int> diStringMatch(string S) {
		vector<int> result;
		set<int> X;
		for (int i = 0; i <= S.size(); ++i)
			X.insert(i);
		for (char c : S)
			if (c == 'I')
			{
				auto it = X.begin();
				result.push_back(*it);
				X.erase(it);
			}
			else
			{
				auto it = X.end();
				--it;
				result.push_back(*it);
				X.erase(it);
			}
		result.push_back(*X.begin());
		return result;
	}
};