class Solution {
public:
	vector<string> buildArray(vector<int>& target, int n) {
		vector<string> result;
		for (int i = 1; i <= *max_element(target.begin(), target.end()); ++i)
		{
			result.push_back("Push");
			if (find(target.begin(), target.end(), i) == target.end())
				result.push_back("Pop");
		}
		return result;
	}
};