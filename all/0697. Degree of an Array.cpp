class Solution {
public:
	int findShortestSubArray(vector<int>& nums) {
		int result = 0;
		int maxFreq = 0;
		vector<int> Freq(50000);
		vector<int> FirstOccurence(50000, -1);
		for (int i = 0; i < nums.size(); ++i)
		{
			int n = nums[i];
			++Freq[n];
			if (FirstOccurence[n] < 0)
				FirstOccurence[n] = i;
			if (Freq[n] > maxFreq)
			{
				maxFreq = Freq[n];
				result = i - FirstOccurence[n] + 1;
			}
			else if (Freq[n] == maxFreq)
				result = min(result, i - FirstOccurence[n] + 1);
		}
		return result;
	}
};