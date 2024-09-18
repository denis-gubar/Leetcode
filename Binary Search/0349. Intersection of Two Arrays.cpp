class Solution {
public:
	vector<int> intersection( vector<int>& nums1, vector<int>& nums2 ) {
		sort( nums1.begin(), nums1.end() );
		sort( nums2.begin(), nums2.end() );
		vector<int> result;
        result.reserve(nums1.size() + nums2.size());
		set_intersection( nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), back_inserter( result ) );
        result.resize( unique( result.begin(), result.end() ) - result.begin() );
		return result;
	}
};