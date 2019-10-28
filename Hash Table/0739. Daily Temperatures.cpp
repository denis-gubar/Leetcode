class Solution {
public:
	vector<int> dailyTemperatures(vector<int>& T) {
		vector<int> result;
		stack<int> S;
		for (int i = T.size() - 1; i >= 0; --i)
		{
			while (!S.empty() && T[S.top()] <= T[i])
				S.pop();
			if (S.empty())
				result.push_back(0);
			else
				result.push_back(S.top() - i);
			S.push(i);
		}
		reverse(result.begin(), result.end());
		return result;
	}
};