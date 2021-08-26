class Solution {
public:
	string removeDuplicates(string s, int k) {
		string result;
		vector<pair<int, int>> stack{ {0, 0} };
		for (int c : s)
		{
			if (c == stack.back().first)
			{
				if (++stack.back().second == k)
					stack.pop_back();
			}
			else
				stack.push_back({ c, 1 });
		}
		for (int i = 0; i < stack.size(); ++i)
			result += string(stack[i].second, stack[i].first);
		return result;
	}
};