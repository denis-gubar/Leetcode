class Solution {
public:
	vector<int> findClosestElements(vector<int>& arr, int k, int x) {
		vector<int> result;
		int N = arr.size();
		int last = upper_bound(arr.begin(), arr.end(), x) - arr.begin();
		int first = last - 1;
		vector<int>	L, R;
		for (; k > 0; --k)
		{
			if (last == N || first >= 0 && x - arr[first] <= arr[last] - x)
			{
				L.push_back(arr[first]);
				--first;
			}
			else
			{
				R.push_back(arr[last]);
				++last;
			}
		}
		reverse_copy(L.begin(), L.end(), back_inserter(result));
		copy(R.begin(), R.end(), back_inserter(result));
		return result;
	}
};