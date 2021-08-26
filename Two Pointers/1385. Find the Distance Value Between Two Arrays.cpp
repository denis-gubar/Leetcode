class Solution {
public:
	int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
		int result = 0;
		sort(arr2.begin(), arr2.end());
		for (int i = 0; i < arr1.size(); ++i)
		{
			int x = arr1[i];
			int count = 0;
			for (int j = 0; !count && j < arr2.size(); ++j)
				count += abs(x - arr2[j]) <= d;
			result += count == 0;
		}
		return result;
	}
};