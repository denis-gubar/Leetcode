class Solution {
public:
	int numWaterBottles(int numBottles, int numExchange) {
		int result = 0, empty = 0;
		while (numBottles)
		{
			result += numBottles;
			empty += numBottles;
			int x = empty / numExchange;
			empty -= x * numExchange;
			numBottles = x;			
		}
		return result;
	}
};