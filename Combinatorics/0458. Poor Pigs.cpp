class Solution {
public:
	int poorPigs(int buckets, int minutesToDie, int minutesToTest) {		
		int result = 0;
		int cases = 1;
		int numberOfTests = minutesToTest / minutesToDie;
		while (cases < buckets)
		{
			cases *= numberOfTests + 1;
			++result;
		}
		return result;
	}
};