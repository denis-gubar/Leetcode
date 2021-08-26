class Solution {
public:
	int arrayNesting(vector<int>& nums) {
		int result = 0;
		int N = nums.size();
		vector<bool> visited(N);
		for(int i = 0; i < N; ++i)
			if (!visited[i])
			{
				int pos = i;
				int count = 0;
				while (!visited[pos])
				{
					visited[pos] = true;
					pos = nums[pos];
					++count;
				}
				result = max(result, count);
			}
		return result;
	}
};