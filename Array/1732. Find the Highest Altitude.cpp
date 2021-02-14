class Solution {
public:
	int largestAltitude(vector<int>& gain) {
		vector<int> A{ 0 };
		partial_sum(gain.begin(), gain.end(), back_inserter(A));
		return *max_element(A.begin(), A.end());
	}
};