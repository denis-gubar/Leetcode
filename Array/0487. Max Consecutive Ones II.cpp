class Solution {
public:
	int findMaxConsecutiveOnes(vector<int>& nums) {
		int result = 1;
		int lastChunk = 0;
		int current = 0;
		for(int n: nums)
			if (n == 0)
			{				
				lastChunk = current + 1;                
				current = 0;
                result = max(result, lastChunk);
			}
			else
			{
				++current;
				result = max(result, current + lastChunk);
			}
		return result;
	}
};