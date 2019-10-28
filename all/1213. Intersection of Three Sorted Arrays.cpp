class Solution {
public:
	vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
		vector<int> A, result;
		set_intersection(arr1.begin(), arr1.end(), arr2.begin(), arr2.end(), back_inserter(A));
		set_intersection(arr3.begin(), arr3.end(), A.begin(), A.end(), back_inserter(result));
		return result;
	}
};
