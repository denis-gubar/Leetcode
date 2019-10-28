class Solution {
public:
	int minSwaps(vector<int>& data) {
		int total = accumulate(data.begin(), data.end(), 0);
		if (total < 2)
			return 0;
		int N = data.size();
		int oneCount = data[0];
		for (int i = 1; i < total; ++i)
			oneCount += data[i];
		int result = total - oneCount;
		for (int i = 1; i + total <= N; ++i)
		{
			oneCount += data[i + total - 1] - data[i - 1];
			result = min(result, total - oneCount);
		}
		return result;
	}
};