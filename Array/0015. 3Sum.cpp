class Solution {
public:
	vector<vector<int>> threeSum( vector<int>& nums ) {
		unordered_map<int, int> S;
		set<vector<int>> result_set;
		for (int i = 0; i < nums.size(); ++i)
			++S[nums[i]];
		if (S.find( 0 ) != S.end() && S[0] >= 3)
			result_set.insert( { 0, 0, 0 } );
		for (int i = 0; i < nums.size(); ++i)
			for (int j = i + 1; j < nums.size(); ++j)
				if ((nums[i] != 0 || nums[j] != 0) && S.find( -nums[i] - nums[j] ) != S.end())
				{
					int k = S[-nums[i] - nums[j]];
					if (nums[i] == -nums[i] - nums[j])
						--k;
					if (nums[j] == -nums[i] - nums[j])
						--k;
					if (k <= 0)
					{
						continue;
					}
					vector<int> A;
					A.push_back( nums[i] );
					A.push_back( nums[j] );
					A.push_back( -nums[i] - nums[j] );
					sort( A.begin(), A.end() );
					result_set.insert( A );
				}
		return vector<vector<int>>(result_set.begin(), result_set.end());
	}
};