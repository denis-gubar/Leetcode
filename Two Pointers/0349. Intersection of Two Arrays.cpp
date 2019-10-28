class Solution {
public:
	vector<int> intersection( vector<int>& nums1, vector<int>& nums2 ) {
		set<int> A( nums1.begin(), nums1.end() );
		set<int> B( nums2.begin(), nums2.end() );
		vector<int> result;
		set_intersection( A.begin(), A.end(), B.begin(), B.end(), back_inserter( result ) );
		return result;
	}
};