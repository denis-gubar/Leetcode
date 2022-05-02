class Solution {
public:
    int minSwaps(vector<int>& data) {
		int N = data.size();
		int total = accumulate(data.begin(), data.end(), 0);
		if (total == N)
			return 0;
		if (total < 2)
			return 0;
		int oneCount = data[0];
		for (int i = 1; i < total; ++i)
			oneCount += data[i];
		int result = total - oneCount;
		for (int i = 1; i + total < 2 * N; ++i)
		{
			oneCount += data[(i + total - 1) % N] - data[(i - 1) % N];
			result = min(result, total - oneCount);
		}
		return result;
    }
};
