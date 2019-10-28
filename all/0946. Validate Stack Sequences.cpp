class Solution {
public:
	bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
		int a = 0;
		stack<int> S;
		for (int b = 0; b < popped.size(); ++b)
		{
			while (S.empty() || S.top() != popped[b])
			{
				if (a == popped.size())
					return false;
				S.push(pushed[a]);
				++a;
			}
			S.pop();
		}
		return S.empty();
	}
};