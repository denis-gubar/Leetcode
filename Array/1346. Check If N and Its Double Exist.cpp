class Solution {
public:
	bool checkIfExist(vector<int>& arr) {
		sort(arr.begin(), arr.end());
		for(int a: arr)
			if (a != 0 && binary_search(arr.begin(), arr.end(), a * 2))
				return true;
		return count(arr.begin(), arr.end(), 0) > 1;
	}
};