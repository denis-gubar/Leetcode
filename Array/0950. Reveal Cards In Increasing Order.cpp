class Solution {
public:
	vector<int> deckRevealedIncreasing(vector<int>& deck) {
		int n = deck.size();
		sort(deck.begin(), deck.end());
		vector<int> result(n);
		queue<int> Q;
		for (int i = 0; i < n; ++i)
			Q.push(i);
		vector<int> A;
		while (!Q.empty())
		{
			int v = Q.front(); Q.pop();
			A.push_back(v);
			if (!Q.empty())
			{
				int u = Q.front(); Q.pop();
				Q.push(u);
			}
		}
		for (int i = 0; i < n; ++i)
			result[A[i]] = deck[i];
		return result;
	}
};