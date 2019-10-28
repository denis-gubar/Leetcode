class Solution {
public:
	int totalNQueens(int n) {
		int result = 0;
		queue<string> Q;
		Q.push({});
		while (!Q.empty())
		{
			string state = Q.front(); Q.pop();
			if (state.size() == n)
			{
				++result;
				continue;
			}
			for (int v = 0; v < n; ++v)
			{
				bool canBeAdded = true;
				for (int i = 0; i < state.size(); ++i)
					if (state[i] == v || state[i] + state.size() - i == v || state[i] - state.size() + i == v)
					{
						canBeAdded = false;
						break;
					}
                if (canBeAdded)
                {
                    string nextState{ state };
                    nextState += v;
                    Q.push(nextState);
                }
			}
		}
		return result;
	}
};