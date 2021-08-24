class Solution {
public:
	int minStoneSum(vector<int>& piles, int k) {
		int result = accumulate(piles.begin(), piles.end(), 0);
		priority_queue<int> PQ;
		for (int x : piles)
			PQ.push(x);
		for (int z = 0; z < k; ++z)
		{
			int x = PQ.top(); PQ.pop();
			int delta = x / 2;
			result -= delta;
			PQ.push(x - delta);
		}
		return result;
	}
};