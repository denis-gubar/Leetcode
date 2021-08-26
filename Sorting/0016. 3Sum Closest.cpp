struct comparator : binary_function< pair<int, int>, pair<int, int>, bool>
{
	comparator(int target): target(target) {}
	bool operator() ( pair<int, int> a, pair<int, int> b ) const
	{
		return abs( a.first - target ) < abs( b.first - target );
	}
private:
	int target;
};
class Solution {
public:
	int threeSumClosest( vector<int>& nums, int target ) {
		int n = nums.size();
		map<int, int> A, B;
		for (int i = 0; i < n; ++i)
			if (A.find( nums[i] ) == A.end() || A[nums[i]] > i)
				A[nums[i]] = i;
		for (int k = 0; k < 2; ++k)
		{
			A.swap( B );
			A.clear();
			for (map<int, int>::iterator it = B.begin(); it != B.end(); ++it)
				for (int i = it->second + 1; i < n; ++i)
				{
					int sum = it->first + nums[i];
					if (A.find( sum ) == A.end() || A[sum] > i)
						A[sum] = i;
				}
		}
		return min_element(A.begin(), A.end(), comparator(target))->first;
	}
};