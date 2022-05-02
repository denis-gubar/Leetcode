class Solution {
public:
	int sign(int x)
	{
		if (x > 0)
			return 1;
		if (x < 0)
			return -1;
		return 0;
	}
	int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
		int result = 0;
		int di = sign(homePos[0] - startPos[0]);
		for (int i = startPos[0]; ;)
		{            
			if (i == homePos[0])
				break;
            i += di;
			result += rowCosts[i];
		}
		int dj = sign(homePos[1] - startPos[1]);
		for (int j = startPos[1]; ;)
		{            
			if (j == homePos[1])
				break;            
            j += dj;
			result += colCosts[j];
		}
		return result;
	}
};