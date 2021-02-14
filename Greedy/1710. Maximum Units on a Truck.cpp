class Solution {
public:
	int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
		int result = 0;
		sort(boxTypes.begin(), boxTypes.end(),
			[](vector<int> const& a, vector<int> const& b)
			{
				return a[1] < b[1];
			});
		while (truckSize > 0 && !boxTypes.empty())
		{
			int box = min<int>(boxTypes.back()[0], truckSize);
			result += box * boxTypes.back()[1];
            truckSize -= box;
			if (boxTypes.back()[0] <= box)
				boxTypes.pop_back();
		}
		return result;
	}
};