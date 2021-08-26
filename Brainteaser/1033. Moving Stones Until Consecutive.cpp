class Solution {
public:
	vector<int> numMovesStones(int a, int b, int c) {
		vector<int>	result{ 0, 0 }, stones{ a, b, c };
		sort(stones.begin(), stones.end());		
		result[1] = stones[2] - stones[0] - 2;
		while (stones[2] - stones[0] > 2)
		{
			++result[0];
			if (stones[0] + 1 == stones[1] || stones[1] + 1 == stones[2])
				break;
			if (stones[1] - stones[0] <= stones[2] - stones[1])
			{
				stones.insert(stones.begin() + 1, stones[0] + 1);
				stones.pop_back();
			}
			else
			{
				stones.insert(stones.begin() + 2, stones[2] - 1);
				stones.erase(stones.begin());
			}
		}
		return result;
	}
};